# Sistema de Detecção de Incêndio com Arduino UNO + ESP

Este projeto utiliza um **Arduino UNO** para leitura de sensores (MQ2 e Sensor de Chama) e uma **ESP** para envio de alertas por e-mail quando for detectado um possível incêndio.

---

## 📦 Pré-requisitos

- **Arduino CLI** instalado  
- **Placa Arduino UNO**  
- **Placa ESP32 ou ESP8266**  
- **Sensor de chama**  
- **Sensor de fumaça MQ2**  

---

## ⚙️ Instalação do Arduino CLI

### Linux
Abra o terminal e rode:

```bash
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh

```

### Windows

Baixe o instalador do Arduino CLI:
👉 Arduino CLI para Windows
https://arduino.github.io/arduino-cli/latest/installation/

Extraia o .zip em uma pasta de sua preferência (exemplo: C:\ArduinoCLI).

Adicione o caminho da pasta arduino-cli.exe nas variáveis de ambiente do Windows (PATH):

Pesquise por Editar variáveis de ambiente do sistema.

Clique em Variáveis de ambiente.

Edite a variável Path e adicione o caminho completo da pasta.

Exemplo: C:\ArduinoCLI\bin.


✅ Verificar instalação

Após a instalação, confirme a versão instalada:

arduino-cli version

Se aparecer a versão, significa que está funcionando.

-------------------------------------------------------

📚 Instalar bibliotecas

Abra o terminal no Linux ou o Prompt de Comando (CMD) no Windows, no diretório MAIN do projeto, e execute:

### Linux:

./install_libs.sh


### Windows:

install_libs.bash


Isso irá baixar todas as bibliotecas utilizadas no projeto.

-------------------------------------------------------

📧 Configuração de e-mail (Gmail)

É necessário utilizar um Gmail com autenticação em duas etapas ativada.

1. Ative a verificação em duas etapas na sua conta.

2. Crie uma senha de aplicativo neste link:
👉 Gerar senha de aplicativo Gmail
https://myaccount.google.com/apppasswords

Anote a senha de 16 dígitos (sem espaços), ela será usada no código.

-------------------------------------------------------

🔥 Testando os sensores

### Sensor de chama

Faça o upload do código flamesensor.ino.

Abra o Serial Monitor e aproxime uma chama (isqueiro, vela).

Verifique se o valor muda conforme esperado.

### Sensor MQ2

Faça o upload do código mq2sensor.ino.

Aguarde alguns minutos até o sensor aquecer (necessário para leituras precisas).

Anote os valores em ambiente aberto (ar limpo).

Gere fumaça próxima ao sensor e anote os valores.

O menor valor obtido com fumaça será o seu threshold.

Edite o arquivo mq2thresh.ino e configure o valor do threshold.
Teste novamente para confirmar que o sensor identifica a fumaça corretamente.

--------------------------------------------------------

🌐 Configuração da ESP (envio de e-mails)

No arquivo main.ino, configure as variáveis:

SSID → Nome da sua rede Wi-Fi ((pode ser de um hotspot de celular))

PASSWORD → Senha da rede Wi-Fi 

AUTHOR_EMAIL → Seu e-mail Gmail (mesmo usado na senha de app)

AUTHOR_PASSWORD → A senha de aplicativo gerada no Gmail (16 dígitos, sem espaços)

RECIPIENT_EMAIL → O e-mail do destinatário do alerta


### Função de envio

O projeto possui a função:

enviarEmail("Assunto do Email", "Mensagem do corpo do Email");

que foi chamada no void loop() e pode ser configurada caso necessário, tanto o assunto quanto a mensagem do corpo do email.

--------------------------------------------------------

🔗 Comunicação Arduino UNO ↔ ESP

O Arduino UNO faz a leitura dos sensores.

Quando detectar fumaça e chama, envia via UART (Serial) um sinal simples ('1') para a ESP.

A ESP interpreta o sinal e envia o e-mail de alerta.

⚠️ Atenção com os níveis lógicos:

UNO (5V) → ESP (3.3V): use divisor resistivo ou level shifter no pino TX do UNO para não queimar a ESP.
