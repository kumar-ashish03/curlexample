# include <stdio.h>
#include <curl/curl.h>

int main (void)
{
         CURL *curl;
         CURLcode res;
         curl = curl_easy_init();        //initialize curl
         if(curl)
        {
                //curl_easy_setopt(curl CURLOPT_URL "http://127.0.0.1:9998/Service/ -d '{"jsonrpc": "2.0", "id": 3, "method": "org.rdk.Wifi.1.connect", "    params": {"ssid": "REDGuest", "passphrase": "R3Dguest", "securityMode": 5 }}'");       // to set url of rdk Api endpoint
                curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:9998/Service/ -d '{\"jsonrpc\": \"2.0 \"id\": 3 \"method\": \"org.rdk.Wifi.1.setEna    bled \"params\": {\"enable\": false} }'");
                //if any additional headers if required
                struct curl_slist *headers = NULL;                                      // to set additional headers
                headers = curl_slist_append(headers, "Content-Type: application/json");
                curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);                    // to set HTTP headers
                curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");                  // to set request method
                res = curl_easy_perform(curl);                                          // to perform request
                curl_easy_cleanup(curl);
                long response_code;                                                     // to print response code
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
                printf("response code: %Ild\n", response_code);
        }
         return 0;
}
