# Irrigação Arduino

Na atualidade agrícola, enfrentamos o desafio significativo da gestão ineficiente da irrigação, resultando em uso excessivo de recursos hídricos e impactos adversos na saúde das plantas. O modelo tradicional de irrigação não se adapta adequadamente às condições climáticas variáveis e às necessidades específicas das plantas, levando a desperdício de água e, em última instância, à ineficiência na produção agrícola.
Como resposta a esse problema, esse projeto propõe a implementação de um sistema inovador de irrigação baseado em Arduino. Este sistema inteligente utiliza sensores de umidade do solo e de chuva conectados a um Arduino Uno. Com algoritmos programados, o Arduino processa dados ambientais, decidindo de forma autônoma quando e quanto irrigar. Através de um relé, o sistema controla uma válvula solenoide para liberar água apenas quando necessário, otimizando a irrigação de acordo com as condições específicas do solo. Essa solução não só reduz o desperdício de água, mas também se adapta dinamicamente às mudanças nas condições climáticas, promovendo uma gestão sustentável e eficiente da irrigação na agricultura.

# Automatizando a Sustentabilidade Agrícola
Na atualidade agrícola, enfrentamos o desafio significativo da gestão ineficiente da irrigação, resultando em uso 
excessivo de recursos hídricos e impactos adversos na saúde das plantas. O modelo tradicional de irrigação não se 
adapta adequadamente às condições climáticas variáveis e às necessidades específicas das plantas, levando a 
desperdício de água e, em última instância, à ineficiência na produção agrícola.
Como resposta a esse problema, esse projeto propõe a implementação de um sistema inovador de irrigação baseado 
em Arduino. Este sistema inteligente utiliza sensores de umidade do solo e de chuva conectados a um Arduino Uno. 
Com algoritmos programados, o Arduino processa dados ambientais, decidindo de forma autônoma quando e quanto 
irrigar. Através de um relé, o sistema controla uma válvula solenoide para liberar água apenas quando necessário, 
otimizando a irrigação de acordo com as condições específicas do solo. Essa solução não só reduz o desperdício de 
água, mas também se adapta dinamicamente às mudanças nas condições climáticas, promovendo uma gestão 
sustentável e eficiente da irrigação na agricultura.

# Implementação dos componentes 

Em um sistema de irrigação Arduino, os componentes principais são o Arduino, sensores, relé, válvula solenoide, 
fonte de energia e, opcionalmente, um display LCD. O esquema de ligação envolve conectar os sensores (como o de 
umidade do solo e de chuva) ao Arduino para coletar dados ambientais. O Arduino processa esses dados e, com base 
em algoritmos programados, controla o relé, que por sua vez ativa a válvula solenoide para liberar água quando 
necessário. A fonte de energia alimenta o sistema, enquanto um display LCD pode exibir informações relevantes. As 
ligações são feitas considerando os pinos e portas adequadas do Arduino, conforme especificado no código do 
projeto. 
Esses componentes desempenham funções específicas em seu projeto de irrigação inteligente controlado por Arduino, 
contribuindo para a automação e otimização da irrigação com base nas condições climáticas e nas necessidades das 
plantas.

# Materiais

*Arduino Uno R3: O Arduino Uno R3 é uma placa de desenvolvimento que utiliza o microcontrolador ATmega328P. 
Ele serve como uma plataforma para programação e controle de dispositivos eletrônicos. O Arduino executa códigos 
que controlam dispositivos conectados a ele, permitindo a automação de tarefas. 

*Sensor de Chuva com Módulo: O sensor de chuva detecta a presença de água na superfície. Ele é composto por 
trilhas condutoras que, quando em contato com a água, diminuem a resistência elétrica, permitindo a detecção de 
chuva. 

*RTC (Real Time Clock): O RTC é um módulo que mantém o controle preciso do tempo, mesmo quando o Arduino 
está desligado. Utiliza um oscilador de cristal para contar o tempo e fornece informações de data e hora para 
aplicações que requerem sincronização temporal. 

*Display LCD 12x2 com Módulo I2C: O display LCD 12x2 é uma tela de cristal líquido que exibe informações 
alfanuméricas em 12 caracteres em 2 linhas. O módulo I2C simplifica a conexão ao Arduino e permite a exibição de 
texto e números. 

*Protoboard 400 Pontos: A protoboard é uma placa perfurada que permite a montagem temporária de circuitos 
eletrônicos. Os componentes são inseridos nos furos da protoboard, facilitando a conexão temporária de fios e 
componentes.

*Módulo Relé 1 Canal 5V 10A: O módulo relé é usado para controlar cargas elétricas de alta potência com sinais de 
baixa potência do Arduino. Quando acionado, o relé fecha ou abre um circuito elétrico, permitindo o controle de 
dispositivos. 

*Válvula Solenoide: Uma válvula solenoide é um dispositivo eletromagnético que controla o fluxo de fluidos, como 
água ou gás. Quando energizada, a bobina solenoide cria um campo magnético que move um êmbolo, abrindo ou 
fechando a válvula. 

*Plugue Macho 2 Polos: Um plugue macho de 2 polos é um conector elétrico simples com dois pinos para conexão de 
fios ou dispositivos. 

*Fio 2,5 mm²: O fio elétrico com seção transversal de 2,5 mm² é usado para conduzir eletricidade em circuitos de 
média potência, conectando componentes elétricos. 

*Fonte Bivolt 9V / 1A para Arduino (Plugue P4): A fonte bivolt fornece energia ao Arduino, produzindo 9 volts com 
uma corrente de 1 ampère, convertendo a energia da rede elétrica em uma voltagem adequada.

*Terminal Fêmea 6mm (para plugar na Válvula Solenoide): Um terminal fêmea de 6mm é um conector elétrico 
usado para conectar fios à válvula solenoide.

*Plugue Engate Rápido para Mangueira: Um plugue de engate rápido é um conector utilizado para acoplar 
mangueiras de forma rápida e segura em sistemas de irrigação.

# Implementação do software 

Esse sistema de irrigação Arduino utilizara um software que comunicação com a Internet via protocolo MQTT, no 
qual a irrigação programada ocorrerá às 8:30, 13:30 e 17:00. Nestes horários, a válvula solenoide será acionada pelo 
Relê e ficará acionada permitindo o fluxo da água. Quando a água escoar pelo furo da garrafa PET e atingir o sensor 
de chuva a irrigação será cessada e iniciará novamente no próximo horário agendado. Caso acabe a energia, o relógio 
possuiu uma bateria interna que manterá o horário atualizado e dará continuidade nos ciclos de irrigação, porém, 
sempre que a energia voltar o sistema iniciará a irrigação. 
É necessário instalar as bibliotecas: LiquidCrystal I2C e RTClib no menu "Ferramentas" - "Gerenciar Bibliotecas...". 
