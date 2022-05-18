#include <iostream>
#include <bits/stdc++.h>
#include <unistd.h>


using namespace std;

class sefer_info{
    char istasyon;

};

class Station{
public:

    char name;

    vector<long> time;
    Station(char name){
        this->name = name;
    }
};

class Hiz_treni{
public:

    string name;
    char instant_location = 'A';
    int max_speed = 200;
    int total_km = 0;
    int genel_bakim_km = 6000;
    int genel_bakim_süresi = 12;
    int kazanc = 60000;
    int min_bakim_suresi = 2;
    bool is_reversed = false;
    int time = 0;
    bool done = false;

};

class Yuk_treni{
public:

    string name;
    char instant_location = 'G';
    int max_speed = 75;
    int total_km = 0;
    int genel_bakim_km = 3000;
    int genel_bakim_süresi = 36;
    int kazanc = 50000;
    int min_bakim_suresi = 3;
    bool is_reversed = false;
    int time = 0;
    bool done = false;

};

class Anahat_treni{
public:

    string name;
    char instant_location = 'N';
    int max_speed = 100;
    int total_km = 0;
    int genel_bakim_km = 6000;
    int genel_bakim_süresi = 12;
    int kazanc = 45000;
    int min_bakim_suresi = 2;
    bool is_reversed = false;
    int time = 0;
    bool done = false;
    bool PdenR = false;
};
string helper_time_hesapla(int time){
    string sa;
    string dk;
    int saat = time / 60;
    if(saat > 24) saat = saat % 24;
    int dakika = time % 60;
    if(saat < 10){
        sa = "0" + to_string(saat);
    }
    else{
        sa = to_string(saat);
    }
    if(dakika < 10){
        dk = "0" + to_string(dakika);
    }
    else{
        dk = to_string(dakika);
    }
    return sa + ":" + dk;
}
string helper_gun(int time){
    time = time / 1440 +1;
    return to_string(time);
}



int main() {
    long profit = 0;
    //Sonra input validation yap
    int time = 0;
    int yuktrensayisi;
    int hizlitrensayisi;
    int anahattrensayisi;
    int number_of_days;
    int yukSefer = 0;
    int hızSefer = 0;
    int anaSefer = 0;

    cout << "Yük Treni Adedi Giriniz : ";
    cin >> yuktrensayisi; //>> hizlitrensayisi >> anahattrensayisi >> number_of_days;
    while (yuktrensayisi < 1) {
        cout << "Minimum yuk treni sayisi 1 olmak zorundadir. Lutfen gecerli bir girdi veriniz : " ;
        cin >> yuktrensayisi;
    }

    cout << "Ana Hat Treni Adedi Giriniz : ";
    cin >> anahattrensayisi;
    while (anahattrensayisi < 1) {
        cout << "Minimum ana hat treni sayisi 1 olmak zorundadir. Lutfen gecerli bir girdi veriniz : ";
        cin >> anahattrensayisi;
    }

    cout << "Hizli Tren Adedi Giriniz : ";
    cin >> hizlitrensayisi;
    while (hizlitrensayisi < 1) {
        cout << "Minimum hizli tren sayisi 2 olmak zorundadir. Lutfen gecerli bir girdi veriniz : ";
        cin >> hizlitrensayisi;
    }


    cout << "Kac Gunluk Sefer Planlamak Istiyorsunuz : ";
    cin >> number_of_days;
    while (number_of_days < 1) {
        cout << "Gecersiz gun sayisi girdiniz. Lutfen gecerli bir gun sayisi giriniz : ";
        cin >> number_of_days;
    }
    vector<Yuk_treni> keep_all_yuk_treni(yuktrensayisi);
    vector<Hiz_treni> keep_all_hizli_tren(hizlitrensayisi);
    vector<Anahat_treni> keep_all_anahat_treni(anahattrensayisi);
    for (int i = 0; i < yuktrensayisi; ++i) {
        keep_all_yuk_treni[i].time = i*5;
    }
    long total_travel_time = number_of_days * 1440;
    int total_train_number = yuktrensayisi+ anahattrensayisi + hizlitrensayisi;


    for (int i = 0; i < hizlitrensayisi; ++i) {
        if (i >= 9){
            keep_all_hizli_tren[i].name = "HT-" + to_string(i+1);
        }
        else{
            keep_all_hizli_tren[i].name = "HT-0" + to_string(i+1);
        }
    }
    for (int i = 0; i < yuktrensayisi; ++i) {
        if (i >= 9){
            keep_all_yuk_treni[i].name = "YT-" + to_string(i+1);
        }
        else{
            keep_all_yuk_treni[i].name = "YT-0" + to_string(i+1);
        }
    }
    for (int i = 0; i < anahattrensayisi; ++i) {
        if (i >= 9){
            keep_all_anahat_treni[i].name = "AT-" + to_string(i+1);
        }
        else{
            keep_all_anahat_treni[i].name = "AT-0" + to_string(i+1);
        }

    }





    Station A('A');
    Station B('B');
    Station C('C');
    Station D('D');
    Station E('E');
    Station F('F');
    Station O('O');

    Station G('G');
    Station H('H');
    Station I('I');
    //Station F('F');
    Station J('J');
    Station K('K');
    Station L('L');

    Station N('N');
    //Station K('K');
    Station X('X');
    Station R('R');
    //Station D('D');
    Station S('S');
    Station P('P');
    vector<Station> stations = {A,B,C,D,E,F,O,G,H,I,J,K,L,N,P,R,S,X};

    vector<pair<char,int>> Rota1;
    Rota1.push_back({'A',100});
    Rota1.push_back({'B',75});
    Rota1.push_back({'C',100});
    Rota1.push_back({'D',75});
    Rota1.push_back({'E',75});
    Rota1.push_back({'F',25});
    Rota1.push_back({'O',0});

    vector<pair<char,int>> Rota2;
    Rota2.push_back({'G',77});
    Rota2.push_back({'H',82});
    Rota2.push_back({'I',50});
    Rota2.push_back({'F',97});
    Rota2.push_back({'J',100});
    Rota2.push_back({'K',112});
    Rota2.push_back({'L',0});

    vector<pair<char,int>> Rota3;
    Rota3.push_back({'N',100});
    Rota3.push_back({'K',100});
    Rota3.push_back({'X',75});
    Rota3.push_back({'R',50});
    Rota3.push_back({'D',50});
    Rota3.push_back({'S',75});
    Rota3.push_back({'P',0});
    while(true){









        //                      YUK TRENİ


        for (int i = 0; i < keep_all_yuk_treni.size(); ++i) {
            if(keep_all_yuk_treni[i].instant_location == 'G' && keep_all_yuk_treni[i].time + 415 > total_travel_time){
                keep_all_yuk_treni[i].done = true;
                continue;
            }
            if(keep_all_yuk_treni[i].is_reversed == false){
                char instant = keep_all_yuk_treni[i].instant_location;
                char next;
                int dist;
                if(instant == 'L'){ // Reverse tarafta harekete geçirmesi için ayarlamaları yap
                    yukSefer++;
                    keep_all_yuk_treni[i].is_reversed = true;
                    profit += keep_all_yuk_treni[i].kazanc;
                    keep_all_yuk_treni[i].time += (keep_all_yuk_treni[i].min_bakim_suresi)*60;
                    break;
                }
                for (int j = 0; j < Rota2.size(); ++j) { //find next station char
                    if(instant == Rota2[j].first){
                        next = Rota2[j+1].first;
                        dist = Rota2[j].second;
                        break;
                    }

                }
                if(instant == 'G' && keep_all_yuk_treni[i].total_km + 518 > keep_all_yuk_treni[i].genel_bakim_km){ //A'da genel bakıma al
                    keep_all_yuk_treni[i].time += keep_all_yuk_treni[i].genel_bakim_süresi *60;
                    keep_all_yuk_treni[i].total_km = 0;
                }
                else{
                    for (int j = 0; j < stations.size(); ++j) { //check if there is a train or not in the next locationne
                        if(stations[j].name == next){
                            keep_all_yuk_treni[i].instant_location = next;
                            keep_all_yuk_treni[i].total_km += dist;
                            keep_all_yuk_treni[i].time += (float(dist) / keep_all_yuk_treni[i].max_speed * 60);
                            cout << "Gun sayisi: " << helper_gun(keep_all_yuk_treni[i].time) << " " <<keep_all_yuk_treni[i].name << " moved from " << instant << " to " << next << " Arrival time: " << helper_time_hesapla(keep_all_yuk_treni[i].time)  <<endl;

                            //stations[j].time.push_back(keep_all_yuk_treni[i].time);
                            break;
                        }
                    }
                }
            }
            else{
                if(keep_all_yuk_treni[i].instant_location == 'L' && keep_all_yuk_treni[i].time + 415 > total_travel_time){
                    keep_all_yuk_treni[i].done = true;
                    continue;
                }
                char instant = keep_all_yuk_treni[i].instant_location;
                char next;
                int dist;
                if(instant == 'G'){ // Reverse tarafta harekete geçirmesi için ayarlamaları yap
                    hızSefer++;
                    keep_all_yuk_treni[i].is_reversed = false;
                    profit += keep_all_yuk_treni[i].kazanc;
                    keep_all_yuk_treni[i].time += keep_all_yuk_treni[i].min_bakim_suresi *60;
                    break;
                }
                for (int j = Rota2.size()-1; j >= 0; --j) { //find next station char
                    if(instant == Rota2[j].first){
                        next = Rota2[j-1].first;
                        dist = Rota2[j-1].second;
                        break;
                    }
                }
                if(instant == 'L' && keep_all_yuk_treni[i].total_km + 518 > keep_all_yuk_treni[i].genel_bakim_km){ //A'da genel bakıma al
                    keep_all_yuk_treni[i].time += keep_all_yuk_treni[i].genel_bakim_süresi *60;
                    keep_all_yuk_treni[i].total_km = 0;

                    //cout << "YUK TRENI " << i << " BAKIMA GIRDI" << endl;
                }
                else{
                    for (int j = 0; j < stations.size(); ++j) { //check if there is a train or not in the next location
                        if(stations[j].name == next){
                            keep_all_yuk_treni[i].instant_location = next;
                            keep_all_yuk_treni[i].total_km += dist;
                            keep_all_yuk_treni[i].time += (float(dist) / keep_all_yuk_treni[i].max_speed * 60);
                            //stations[j].time.push_back(float(dist) / keep_all_yuk_treni[i].max_speed * 60);
                            cout << "Gun sayisi: " << helper_gun(keep_all_yuk_treni[i].time) << " " <<keep_all_yuk_treni[i].name << " moved from " << instant << " to " << next << " Arrival time: " << helper_time_hesapla(keep_all_yuk_treni[i].time)  <<endl;

                            break;
                        }
                    }
                }
            }
        }





        /////                   HIZ TRENİ





        /////                   HIZ TRENİ



        for (int i = 0; i < keep_all_hizli_tren.size(); ++i) {
            if(keep_all_hizli_tren[i].instant_location == 'A' && keep_all_hizli_tren[i].time + 265 > total_travel_time){
                keep_all_hizli_tren[i].done = true;
                continue;
            }
            if(keep_all_hizli_tren[i].is_reversed == false){
                char instant = keep_all_hizli_tren[i].instant_location;
                char next;
                int dist;
                if(instant == 'O'){ // Reverse tarafta harekete geçirmesi için ayarlamaları yap
                    hızSefer++;
                    keep_all_hizli_tren[i].is_reversed = true;
                    profit += keep_all_hizli_tren[i].kazanc;
                    keep_all_hizli_tren[i].time += (keep_all_hizli_tren[i].min_bakim_suresi)*60;
                    break;
                }
                for (int j = 0; j < Rota1.size(); ++j) { //find next station char
                    if(instant == Rota1[j].first){
                        next = Rota1[j+1].first;
                        dist = Rota1[j].second;
                        break;
                    }

                }
                if(instant == 'A' && keep_all_hizli_tren[i].total_km + 450 > keep_all_hizli_tren[i].genel_bakim_km){ //A'da genel bakıma al
                    keep_all_hizli_tren[i].time += keep_all_hizli_tren[i].genel_bakim_süresi *60;
                    keep_all_hizli_tren[i].total_km = 0;

                }
                else{
                    for (int j = 0; j < stations.size(); ++j) { //check if there is a train or not in the next locationne
                        if(stations[j].name == next){
                            int wait_or_not = false;
                            int varis_zamani = keep_all_hizli_tren[i].time + (float(dist)/keep_all_hizli_tren[i].max_speed) *60;
                            for (int k = 0; k < stations[j].time.size(); ++k) {
                                if(abs(varis_zamani  - stations[j].time[k]) < 20 ){
                                    keep_all_hizli_tren[i].time += 1;
                                    //cout << "Hiz Tren " << i << " waited at " << instant << endl;
                                    int index_instant;
                                    for (int l = 0; l < stations.size(); ++l) {
                                        if(stations[l].name == instant){
                                            index_instant = l;
                                            wait_or_not = true;
                                            break;
                                        }
                                    }
                                    stations[index_instant].time.push_back(keep_all_hizli_tren[i].time);
                                    break;
                                }
                            }
                            if(wait_or_not == false){ // gidiyorsa
                                keep_all_hizli_tren[i].instant_location = next;
                                keep_all_hizli_tren[i].total_km += dist;
                                keep_all_hizli_tren[i].time += (float(dist) / keep_all_hizli_tren[i].max_speed * 60) + 15;
                                cout << "Gun sayisi: " << helper_gun(keep_all_hizli_tren[i].time) << " " <<keep_all_hizli_tren[i].name << " moved from " << instant << " to " << next << " Arrival time: " << helper_time_hesapla(keep_all_hizli_tren[i].time)  <<endl;
                                stations[j].time.push_back(varis_zamani);
                            }
                            wait_or_not = false;
                            break;
                        }
                    }
                }
            }
            else{
                if(keep_all_hizli_tren[i].instant_location == 'O' && keep_all_hizli_tren[i].time + 265 > total_travel_time){
                    keep_all_hizli_tren[i].done = true;
                    continue;
                }
                char instant = keep_all_hizli_tren[i].instant_location;
                char next;
                int dist;
                if(instant == 'A'){ // Reverse tarafta harekete geçirmesi için ayarlamaları yap
                    hızSefer++;
                    keep_all_hizli_tren[i].is_reversed = false;
                    profit += keep_all_hizli_tren[i].kazanc;
                    keep_all_hizli_tren[i].time += keep_all_hizli_tren[i].min_bakim_suresi *60;
                    break;
                }
                for (int j = Rota1.size()-1; j >= 0; --j) { //find next station char
                    if(instant == Rota1[j].first){
                        next = Rota1[j-1].first;
                        dist = Rota1[j-1].second;
                        break;
                    }
                }
                if(instant == 'O' && keep_all_hizli_tren[i].total_km + 450 > keep_all_hizli_tren[i].genel_bakim_km){ //A'da genel bakıma al
                    keep_all_hizli_tren[i].time += keep_all_hizli_tren[i].genel_bakim_süresi *60;
                    keep_all_hizli_tren[i].total_km = 0;

                }
                else{
                    for (int j = 0; j < stations.size(); ++j) { //check if there is a train or not in the next location
                        if(stations[j].name == next){
                            int wait_or_not = false;
                            int varis_zamani = keep_all_hizli_tren[i].time + (float(dist)/keep_all_hizli_tren[i].max_speed) *60;
                            for (int k = 0; k < stations[j].time.size(); ++k) {
                                if(abs(varis_zamani  - stations[j].time[k]) < 20 ){
                                    keep_all_hizli_tren[i].time += 1;
                                    cout << "Hiz Tren " << i << " waited at " << instant << endl;
                                    int index_instant;
                                    for (int l = 0; l < stations.size(); ++l) {
                                        if(stations[l].name == instant){
                                            index_instant = l;
                                            wait_or_not = true;
                                            break;
                                        }
                                    }
                                    stations[index_instant].time.push_back(keep_all_hizli_tren[i].time);
                                    break;
                                }
                            }
                            if(wait_or_not == false){ // gidiyorsa
                                keep_all_hizli_tren[i].instant_location = next;
                                keep_all_hizli_tren[i].total_km += dist;
                                keep_all_hizli_tren[i].time += (float(dist) / keep_all_hizli_tren[i].max_speed * 60) + 15;
                                cout << "Gun sayisi: " << helper_gun(keep_all_hizli_tren[i].time) << " " <<keep_all_hizli_tren[i].name << " moved from " << instant << " to " << next << " Arrival time: " << helper_time_hesapla(keep_all_hizli_tren[i].time)  <<endl;
                                stations[j].time.push_back(varis_zamani);
                            }
                            wait_or_not = false;
                            break;
                        }
                    }
                }
            }
        }


        ///////////////// ANAHAT TRENI //////////////

        for (int i = 0; i < keep_all_anahat_treni.size(); ++i) {
            if(keep_all_anahat_treni[i].instant_location == 'N' && keep_all_anahat_treni[i].time + 450 > total_travel_time){
                keep_all_anahat_treni[i].done = true;
                continue;
            }
            if(keep_all_anahat_treni[i].is_reversed == false){
                char instant = keep_all_anahat_treni[i].instant_location;
                char next;
                int dist;
                if(instant == 'P'){ // Reverse tarafta harekete geçirmesi için ayarlamaları yap
                    hızSefer++;
                    keep_all_anahat_treni[i].is_reversed = true;
                    profit += keep_all_anahat_treni[i].kazanc;
                    keep_all_anahat_treni[i].time += (keep_all_anahat_treni[i].min_bakim_suresi)*60;
                    break;
                }
                for (int j = 0; j < Rota3.size(); ++j) { //find next station char
                    if(instant == Rota3[j].first){
                        next = Rota3[j+1].first;
                        dist = Rota3[j].second;

                        break;
                    }

                }
                if(instant == 'N' && keep_all_anahat_treni[i].total_km + 450 > keep_all_anahat_treni[i].genel_bakim_km){ //A'da genel bakıma al
                    keep_all_anahat_treni[i].time += keep_all_anahat_treni[i].genel_bakim_süresi *60;
                    keep_all_anahat_treni[i].total_km = 0;


                }
                else{
                    for (int j = 0; j < stations.size(); ++j) { //check if there is a train or not in the next locationne
                        if(stations[j].name == next){
                            int wait_or_not = false;
                            int varis_zamani = keep_all_anahat_treni[i].time + (float(dist)/keep_all_anahat_treni[i].max_speed) *60;
                            for (int k = 0; k < stations[j].time.size(); ++k) {
                                if(abs(varis_zamani  - stations[j].time[k]) < 25 ){
                                    keep_all_anahat_treni[i].time += 1;
                                    //cout << "Ana Hat Tren " << i << " waited at " << instant << endl;
                                    int index_instant;
                                    for (int l = 0; l < stations.size(); ++l) {
                                        if(stations[l].name == instant){
                                            index_instant = l;
                                            wait_or_not = true;
                                            break;
                                        }
                                    }
                                    stations[index_instant].time.push_back(keep_all_anahat_treni[i].time);
                                    break;
                                }
                            }
                            if(wait_or_not == false){ // gidiyorsa
                                keep_all_anahat_treni[i].instant_location = next;
                                keep_all_anahat_treni[i].total_km += dist;
                                keep_all_anahat_treni[i].time += (float(dist) / keep_all_anahat_treni[i].max_speed * 60) + 20;
                                cout << "Gun sayisi: " << helper_gun(keep_all_anahat_treni[i].time) << " " <<keep_all_anahat_treni[i].name << " moved from " << instant << " to " << next << " Arrival time: " << helper_time_hesapla(keep_all_anahat_treni[i].time)  <<endl;
                                stations[j].time.push_back(varis_zamani);
                            }
                            wait_or_not = false;
                            break;
                        }
                    }
                }
            }
            else{
                if(keep_all_anahat_treni[i].instant_location == 'P' && keep_all_anahat_treni[i].time + 450 > total_travel_time){
                    keep_all_anahat_treni[i].done = true;
                    continue;
                }
                char instant = keep_all_anahat_treni[i].instant_location;
                char next;
                int dist;
                if(instant == 'N'){ // Reverse tarafta harekete geçirmesi için ayarlamaları yap
                    hızSefer++;
                    keep_all_anahat_treni[i].is_reversed = false;
                    profit += keep_all_anahat_treni[i].kazanc;
                    keep_all_anahat_treni[i].time += keep_all_anahat_treni[i].min_bakim_suresi *60;
                    break;
                }
                for (int j = Rota3.size()-1; j >= 0; --j) { //find next station char
                    if(instant == Rota3[j].first){
                        next = Rota3[j-1].first;
                        dist = Rota3[j-1].second;
                        break;
                    }
                }
                if(instant == 'P' && keep_all_anahat_treni[i].total_km + 450 > keep_all_anahat_treni[i].genel_bakim_km){ //A'da genel bakıma al
                    keep_all_anahat_treni[i].time += keep_all_anahat_treni[i].genel_bakim_süresi *60;
                    keep_all_anahat_treni[i].total_km = 0;
                }
                else{
                    for (int j = 0; j < stations.size(); ++j) { //check if there is a train or not in the next location
                        if(stations[j].name == next){
                            int wait_or_not = false;
                            int varis_zamani = keep_all_anahat_treni[i].time + (float(dist)/keep_all_anahat_treni[i].max_speed) *60;
                            for (int k = 0; k < stations[j].time.size(); ++k) {
                                if(abs(varis_zamani  - stations[j].time[k]) < 25 ){
                                    keep_all_anahat_treni[i].time += 1;
                                    //cout << "Ana Hat Tren " << i << " waited at " << instant << endl;
                                    int index_instant;
                                    for (int l = 0; l < stations.size(); ++l) {
                                        if(stations[l].name == instant){
                                            index_instant = l;
                                            wait_or_not = true;
                                            break;
                                        }
                                    }
                                    stations[index_instant].time.push_back(keep_all_anahat_treni[i].time);
                                    break;
                                }
                            }
                            if(wait_or_not == false){ // gidiyorsa
                                keep_all_anahat_treni[i].instant_location = next;
                                keep_all_anahat_treni[i].total_km += dist;
                                keep_all_anahat_treni[i].time += (float(dist) / keep_all_anahat_treni[i].max_speed * 60) + 20;
                                cout << "Gun sayisi: " << helper_gun(keep_all_anahat_treni[i].time) << " " <<keep_all_anahat_treni[i].name << " moved from " << instant << " to " << next << " Arrival time: " << helper_time_hesapla(keep_all_anahat_treni[i].time)  <<endl;
                                stations[j].time.push_back(varis_zamani);
                            }
                            wait_or_not = false;
                            break;
                        }
                    }
                }
            }
        }


        int tmp = 0;
        for (int i = 0; i < keep_all_hizli_tren.size(); ++i) {
            if(keep_all_hizli_tren[i].done == true) tmp++;
        }
        for (int i = 0; i < keep_all_yuk_treni.size(); ++i) {
            if(keep_all_yuk_treni[i].done == true) tmp++;
        }
        for (int i = 0; i < keep_all_anahat_treni.size(); ++i) {
            if(keep_all_anahat_treni[i].done == true) tmp++;
        }
        if(tmp == total_train_number) break;
        else tmp = 0;
    }
    cout << "Profit " << profit << endl;
    return 0;
}

