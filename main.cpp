#include <iostream>
#include <string>
#include <curl/curl.h>

//sudo apt install libcurl4-openssl-dev
//necessaria para a busca

using namespace std;

int main (){
    CURL *curl;
    CURLcode res;

    string pokemonSelecionado;
    string urlpokemon;

    curl = curl_easy_init();

    system("clear");

    cout << "digite o nome do seu pokemon\n";

    getline(cin, pokemonSelecionado);

    urlpokemon = "https://pokeapi.co/api/v2/pokemon/" + pokemonSelecionado;

    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, urlpokemon.c_str());
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        cout << res << endl;
    }

    return 0;
}