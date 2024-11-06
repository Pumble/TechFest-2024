comandos AT comunes que puedes enviar al módulo HC-05 para configurarlo y controlarlo:

# Comandos Básicos:

AT: Verifica la conexión con el módulo.
AT+RESET: Reinicia el módulo.
AT+VERSION: Muestra la versión del firmware.
AT+ORGL: Restaura la configuración de fábrica.
Configuración de Roles:

AT+ROLE=0: Configura el módulo como esclavo.
AT+ROLE=1: Configura el módulo como maestro.
Configuración de Conexión:

AT+CMODE=0: Conectar a una dirección específica.
AT+CMODE=1: Conectar a cualquier dispositivo.
AT+BIND=<address>: Establece la dirección MAC del dispositivo esclavo (por ejemplo, AT+BIND=0011,22,334455).
Configuración de Velocidad de Baud:

AT+UART=<baudrate>,0,0: Configura la velocidad de baud (por ejemplo, AT+UART=9600,0,0).
Configuración del Nombre:

AT+NAME=<name>: Cambia el nombre del dispositivo (por ejemplo, AT+NAME=MyHC05).
Configuración del PIN:

AT+PSWD=<pin>: Cambia el PIN de emparejamiento (por ejemplo, AT+PSWD=1234).
Configuración de Potencia:

AT+CLASS=<class>: Configura la clase de potencia (por ejemplo, AT+CLASS=1).
Configuración de Enlace:

AT+LINK=<address>: Conecta al dispositivo con la dirección MAC especificada.
Configuración de Modo de Trabajo:

AT+INIT: Inicializa el módulo SPP.
AT+INQ: Inicia la búsqueda de dispositivos.
Configuración de Seguridad:

AT+SENM=<mode>: Configura el modo de seguridad (por ejemplo, AT+SENM=3,1).
Estos comandos se envían al módulo HC-05 mientras está en modo de comandos AT. Asegúrate de que el módulo esté en modo AT antes de enviar estos comandos. Puedes enviar estos comandos utilizando BT.print("comando") en tu código Arduino, como se muestra en tu archivo control_funduino.ino.