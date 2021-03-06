#include "AUTOMOBIL.h"


class MINI : public AUTOMOBIL
{
    int tractiune_fata;///0-SPATE 1-FATA
public:
    MINI(string M=" ",int an_f=0,float litr=0.0,float lung=0.0,int tr_fat=1,float price=-1.0):AUTOMOBIL(M,an_f,litr,lung,price),tractiune_fata(tr_fat)
    {}
    MINI(MINI& M):AUTOMOBIL(M),tractiune_fata(M.tractiune_fata){}
    ~MINI(){}
    MINI& operator= (MINI& mi);
    string tip () {return "MINI";}
    void citire(istream& in);
    void citire(ifstream& in);
    void afisare(ostream& out);
    int check()
    {
        if(an_fabr>2018) return 1;
        if(pret<0) return 2;
        if(Marca==" ") return 3;
        if(lungime>4) return 4;
    }
    ///FRIEND
    friend ifstream& operator>> (ifstream&in, MINI& a);
    friend istream& operator>> (istream&in, MINI& a);
    friend ostream& operator<< (ostream&out, MINI& a);
};

MINI& MINI::operator= (MINI& mi)
{
    AUTOMOBIL::operator=(mi);
    tractiune_fata=mi.tractiune_fata;
    return *this;
}

void MINI::citire (istream& in)
{
    cout<<"\nSe citesc date pentru Masina MINI:\nNumele: ";
    getline(in,Marca);
    cout<<"Anul fabricatiei | Capacitate rezervol | Lungimea masinii\n";
    in>>an_fabr>>litraj>>lungime;
    cout<<"Tractiune: 1.FATA sau 2.SPATE?\n";
    string trac;
    in>>trac;
    trac=UPPER(trac);
    if(trac=="1" || trac=="FATA") tractiune_fata=1;
    else if(trac=="2" || trac=="SPATE") tractiune_fata=0;
    cout<<"PRETUL: ";
    in>>pret;
string n;
getline(in,n);
}

void MINI::citire (ifstream& in)
{
    cout<<"\nSe citesc date pentru Masina MINI:\nNumele: ";
    getline(in,Marca);
    cout<<"Anul fabricatiei | Capacitate rezervol | Lungimea masinii\n";
    in>>an_fabr>>litraj>>lungime;
    cout<<"Tractiune: 1.FATA sau 2.SPATE?\n";
    string trac;
    in>>trac;
    trac=UPPER(trac);
    if(trac=="1" || trac=="FATA") tractiune_fata=1;
    else if(trac=="2" || trac=="SPATE") tractiune_fata=0;
    cout<<"PRETUL: ";
    in>>pret;
string n;
getline(in,n);
}


void MINI::afisare (ostream& out)
{
    if(Marca!= " ")
        {
        out<<"Marca : "<<Marca<<" | Anul: "<<an_fabr<<" | Lungime: "<<lungime<<"m | Litraj:  "<<litraj<<" L";
        if(tractiune_fata) out<<" | Tractiune: FATA";
        else out<<" | Tractiune: SPATE";
        out<<"\n|Tip: Mini";
        out<<" | PRET: "<<pret<<" EURO\n\n";
        }
}

istream& operator>> (istream&in, MINI& m)
{
    m.citire(in);
    return in;
}

ifstream& operator>> (ifstream&in, MINI& m)
{
    m.citire(in);
    return in;
}

ostream& operator<< (ostream&out, MINI& m)
{
    m.afisare(out);
    return out;
}

