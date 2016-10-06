//
//  main.c
//  rescalctest
//
//  Created by Jonas Hüsser on 03.10.16.
//  Copyright © 2016 Jonas Hüsser. All rights reserved.
//

#include <stdio.h> /* printf, sprintf */
#include <curl/curl.h>





int main(int argc, const char * argv[]) {
    
    CURL *hnd = curl_easy_init();
    
    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(hnd, CURLOPT_URL, "https://api.widerstandsberechner.ch/api.php?firstcolor=blue&secondcolor=orange&thirdcolor=yellow&fourthcolor=silver&hasFiveRings=0&resultInText=1");
    
    struct curl_slist *headers = NULL;
    //headers = curl_slist_append(headers, "postman-token: 0303ff27-260e-52ca-77f4-8a98089355c7");
    headers = curl_slist_append(headers, "cache-control: no-cache");
    headers = curl_slist_append(headers, "as-key: eh3X9PIiWPo5jlFkebMR");
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);
    
    CURLcode ret = curl_easy_perform(hnd);
    
    
        return 0;
}
