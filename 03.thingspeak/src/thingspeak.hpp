#include <Arduino.h>
#include <stdio.h>
#include <esp_http_client.h>
#include "esp_log.h"

static const char* TAG = "THISP";

void SendDataThingspeak(int temperature, int humidity, int dryness)
{
	char url[256];
	sprintf (url, "http://api.thingspeak.com/update?api_key=%s&field1=%d&field2=%d&field3=%d",
				THINGSPEAK_KEY, temperature, humidity, dryness);
				
	esp_http_client_config_t config = {
		.url = url,
		.method = HTTP_METHOD_GET,
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);
    
     // GET
    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK) {
        // ESP_LOGI(TAG, "HTTP GET Status = %d , content_length = %"PRId64 ,
        //         esp_http_client_get_status_code(client),
        //         esp_http_client_get_content_length(client));
        Serial.println("Sensor data was sent successfully. code: " + String(esp_http_client_get_status_code(client)));
    } else {
        // ESP_LOGE(TAG, "HTTP GET request failed: %s", esp_err_to_name(err));
        Serial.println("Failed to send data. code: " + String(err));
    }
    
    esp_http_client_cleanup(client);
}