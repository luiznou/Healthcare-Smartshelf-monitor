
#define DHTPIN 15  // GPIO simulado (não utilizado de verdade)

// Estrutura simulada de uma tag UHF com temperatura e umidade
struct TagSim {
  String epc;
  float tempTag;
  float humidity;
};

TagSim tags[] = {
  {"FM13DT160_TAG_001", 5.5, 45.2},
  {"FM13DT160_TAG_002", 7.8, 50.1},
  {"FM13DT160_TAG_003", 9.1, 55.7}
};

int idx = 0;

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println("Iniciando Smart Shelf - Simulação de pacote MQTT para envio externo (5G)");
}

void loop() {
  delay(3000);

  // Simula leitura de uma tag
  TagSim t = tags[idx++];
  idx %= 3;

  // Monta o pacote JSON simulado
  String payload = "{";
  payload += "\"epc\":\"" + t.epc + "\",";
  payload += "\"temp\":" + String(t.tempTag,1) + ",";
  payload += "\"hum\":" + String(t.humidity,1) + ",";
  if (t.tempTag < 2.0 || t.tempTag > 8.0)
    payload += "\"alert\":\"true\"";
  else
    payload += "\"alert\":\"false\"";
  payload += "}";

  // Exibe como se estivesse pronto para envio por MQTT/5G
  Serial.println("📦 Pacote preparado para envio externo:");
  Serial.println(payload);
}
