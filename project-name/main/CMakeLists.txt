idf_component_register(SRCS "sntp_time_sync.c" "wifi_reset_button.c" "app_nvs.c" "DHT22.c" "http_server.c" "wifi_app.c" "rgb_led.c" "main.c" "app_nvs.c" "wifi_reset_button.c" "sntp_time_sync.c" "aws_iot.c"
                    INCLUDE_DIRS "." 
                    EMBED_FILES "webpage/app.css" "webpage/app.js" "webpage/favicon.ico" "webpage/index.html" "webpage/jquery-3.3.1.min.js")
target_add_binary_data(${COMPONENT_TARGET} "certs/aws_root_ca_pem" TEXT)
target_add_binary_data(${COMPONENT_TARGET} "certs/certificate_pem_crt" TEXT)
target_add_binary_data(${COMPONENT_TARGET} "certs/private_pem_key" TEXT)