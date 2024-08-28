/////////////////////////////////////////////////////////////////////////////

///	Purpose: NVS Configuration Header

/// Author: Nubal Manhas

/////////////////////////////////////////////////////////////////////////////

/*
    Save station mode WiFi credentials to NVS
    return = ESP_OK if successful
*/
esp_err_t app_nvs_save_sta_creds(void);

/*
    Loads the previously saved credentials from NVS
    return = true if previosuly saved credentials were found.
*/
bool app_nvs_load_sta_creds(void);

/*
    Clears station mode credentials from NVs 
    return = ESP_OK if successful
*/
esp_err_t app_nvs_clear_sta_creds(void);

