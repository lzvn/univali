#include <iostream>
#include <string>

using namespace std;


#define ZOMBOS 0
#define FRANKEN 1
#define HAPPY 2

//caracteristicas
#define NULA -1
#define VEGITAS 0
#define WACKUS 1
#define SPRITEM 2

#define NUM_TIPOS_CARAC 3

class Monstro {
    public:
    Monstro(); //cria um monstro totalmente nulo
    Monstro(short int cabeca, short int caracteristicas);
    Monstro(short int cabeca, short int olhos, short int nariz, short int boca);
    string verNome();
    void desenharMonstro();

    static string nomesCabeca(short int tipo);
    static string nomesCaracteristicas(short int tipo);


    private:
    string nome;
    short int cabeca;
    short int olhos;
    short int nariz;
    short int boca;

    string nomearMonstro();
};





int main() {
    short int cabeca_escolhida;
    short int caracs_escolhidas[3];

    cout<<"Gerador de monstros\n"<<endl;

    for(int i : {ZOMBOS, FRANKEN, HAPPY}) {
        cout << i+1 <<" - "<< Monstro::nomesCabeca(i) << endl;
    }
    cout<<"Digite o código do tipo de cabeca que você gostaria: ";
    cin>>cabeca_escolhida;
    cabeca_escolhida--;
    cout<<endl;
    
    int carac_index = 0;
    for(string carac : {"olhos", "nariz", "boca"}) {
        for(int i : {NULA, VEGITAS, WACKUS, SPRITEM}) {
            cout << i+1 <<" - "<< Monstro::nomesCaracteristicas(i) << endl;
        }

        cout<<"Digite o código do tipo de "<<carac<<" que você gostaria: ";
        cin>>caracs_escolhidas[carac_index];
        caracs_escolhidas[carac_index]--;
        carac_index++;
        cout<<endl;
    }

    Monstro monstro_criado = Monstro(cabeca_escolhida, caracs_escolhidas[0], caracs_escolhidas[1], caracs_escolhidas[2]);

    cout<<"Um novo monstro foi criado! Seu nome é "<<monstro_criado.verNome()<<"!"<<endl;
    cout<<"Sua cabeça é "<<Monstro::nomesCabeca(cabeca_escolhida)<<endl;
    cout<<"Seus olhos são "<<Monstro::nomesCaracteristicas(caracs_escolhidas[0])<<endl;
    cout<<"Seu nariz é "<<Monstro::nomesCaracteristicas(caracs_escolhidas[1])<<endl;
    cout<<"Sua boca é "<<Monstro::nomesCaracteristicas(caracs_escolhidas[2])<<endl;

    monstro_criado.desenharMonstro();
}





Monstro::Monstro() {
    this->nome = "";
    this->cabeca = NULA;
    this->olhos = NULA;
    this->nariz = NULA;
    this->boca = NULA;
}

Monstro::Monstro(short int cabeca, short int caracteristicas) {
    this->cabeca = cabeca;
    this->olhos = caracteristicas;
    this->nariz = caracteristicas;
    this->boca = caracteristicas;

    nome = nomearMonstro();
}


Monstro::Monstro(short int cabeca, short int olhos, short int nariz, short int boca) {
    this->cabeca = cabeca;
    this->olhos = olhos;
    this->nariz = nariz;
    this->boca = boca;

    nome = nomearMonstro();
}

string Monstro::verNome() {
    return nome;
}

string Monstro::nomesCabeca(short int tipo) {
    switch (tipo)
    {
    case ZOMBOS:
        return "Zombos";
        break;
    case FRANKEN:
        return "Franken";
        break;
    case HAPPY:
        return "Happy";
        break;
    default:
        return "Nulo";
        break;
    }
}

string Monstro::nomesCaracteristicas(short int tipo) {
        switch (tipo)
    {
    case VEGITAS:
        return "Vegitas";
        break;
    case WACKUS:
        return "Wackus";
        break;
    case SPRITEM:
        return "Spritem";
        break;
    default:
        return "Nulo";
        break;
    }
}

string Monstro::nomearMonstro() {
    short int carac_predom = NULA;
    short int carac_count[NUM_TIPOS_CARAC];

    for (short int carac : {olhos, nariz, boca}) {
        if(carac < 0 || carac >= NUM_TIPOS_CARAC) {
            continue;
        } else {
            carac_count[carac]++;
        }
    }

    /*codigo abaixo foi feito para um número de 3 caracteristicas fisicas (olhos, nariz e boca), nao funciona noutros casos*/
    for(int i = 0; i < NUM_TIPOS_CARAC; i++) {
        if(carac_count[i] >= 2) {
            carac_predom = i;
            break;
        }
    }

    if(carac_predom == NULA) {
        if(olhos != NULA) {
            carac_predom = olhos;
        } else if(boca != NULA) {
            carac_predom = boca;
        } else if(nariz != NULA) {
            carac_predom = nariz;
        }
    }

    return nomesCabeca(cabeca)+" "+nomesCaracteristicas(carac_predom);
}

void Monstro::desenharMonstro() {
    /*Esta função serve para representar o ato de desenhar o monstro recém-criado, no método discutivo no trabalho (desenhar a cabeça e as características
    conforme os tipos de cada), porém não será implementada.*/
}