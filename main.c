// gcc main.c -L/usr/lib/x86_64-linux-gnu -lcurl

#include <stdio.h>
#include <curl/curl.h>

int main() {
    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "failed to initialize curl");
    }

    CURLcode res;
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:4001/status?pretty");
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    //printf("CURLcode: %d\n", res);

    return 0;
}
