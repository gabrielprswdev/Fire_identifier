#include <WiFi.h>
#include <ESP_Mail_Client.h>
#include "time.h"

const char* ssid = "wifi ssid";
const char* password = "wifi password";
bool emailEnviado = false;

#define AUTHOR_EMAIL "seuemail@gmail.com"
#define AUTHOR_PASSWORD "senha de 16 digitos"
#define RECIPIENT_EMAIL "destinatario@gmail.com"

SMTPSession smtp;

void smtpCallback(SMTP_Status status){
  Serial.println(status.info());
}

void enviarEmail(const char* assunto, const char* mensagem) {
  ESP_Mail_Session session;
  session.server.host_name = "smtp.gmail.com";
  session.server.port = 465;
  session.login.email = AUTHOR_EMAIL;
  session.login.password = AUTHOR_PASSWORD;
  session.login.user_domain = "";

  smtp.debug(1);
  smtp.callback(smtpCallback);

  SMTP_Message msg;
  msg.sender.name = "ESP32";
  msg.sender.email = AUTHOR_EMAIL;
  msg.subject = assunto;
  msg.addRecipient("Destinatário", RECIPIENT_EMAIL);
  msg.text.content = mensagem;

  if (!smtp.connect(&session)) {
    Serial.println("Falha ao conectar ao servidor SMTP.");
    return;
  }

  if (!MailClient.sendMail(&smtp, &msg)) {
    Serial.println("Falha ao enviar email.");
  } else {
    Serial.println("Email enviado com sucesso!");
    emailEnviado = true;
  }
}

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");

  configTime(0, 0, "pool.ntp.org", "time.nist.gov");
  Serial.print("Ajustando hora");
  time_t now = time(nullptr);
  while (now < 100000) {
    delay(500);
    Serial.print(".");
    now = time(nullptr);
  }
  Serial.println("\nHora ajustada!");

}

void loop() {

  if (Serial.available()) {
    char dado = Serial.read();
    if (dado == '1' && !emailEnviado) {
      Serial.println("Incêndio detectado, enviando alerta...");
      enviarEmail("Aviso de incêndio do ESP", "Este é um aviso de incêndio.");
    }
  }

}
