/////////////////////////////////////////////////////////////////////////////

///	Purpose: Wifi Reset Button Configuration Header

/// Author: Nubal Manhas

/////////////////////////////////////////////////////////////////////////////

//default interrupt flag
#define ESP_INTR_FLAG_DEFAULT 0

//Wifi reset button is the BOOT button on the DevKit
#define WIFI_RESET_BUTTON     0 

/*
    Configures WiFi reset button and interrupt configuration
*/
void wifi_reset_button_config(void);