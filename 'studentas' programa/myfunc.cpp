#include "myfunc.h"
#include "myvec.h"

studentas::studentas(const studentas &naujas)
{
   Vardas=naujas.Vardas;
   Pavarde=naujas.Pavarde;
   for (int i=0; i<Nd.size(); i++)
   {
        Nd.at(i)=naujas.Nd.at(i);
   }
   Egz=naujas.Egz;
   gmediana=naujas.gmediana;
   gvidurkis=naujas.gvidurkis;
}

studentas::studentas(studentas &&kitas)
{
    Vardas=move(kitas.Vardas);
    Pavarde=move(kitas.Pavarde);
    Nd=move(kitas.Nd);
    Egz=move(kitas.Egz);
    gmediana=move(kitas.gmediana);
    gvidurkis=move(kitas.gvidurkis);

    kitas.Nd.clear(); kitas.Nd.shrink_to_fit();
    kitas.Vardas=kitas.Pavarde="";
    kitas.Egz=kitas.gmediana=kitas.gvidurkis=0;
}

studentas &studentas::operator=(const studentas &naujas)
{
    if (this!=&naujas)
    {
        Vardas=naujas.Vardas;
        Pavarde=naujas.Pavarde;
        Nd=naujas.Nd;
        Egz=naujas.Egz;
        gmediana=naujas.gmediana;
        gvidurkis=naujas.gvidurkis;
    }
    return *this;
}

studentas &studentas::operator=(studentas &&kitas)
{
    if (this!=&kitas)
    {
        Vardas=move(kitas.Vardas);
        Pavarde=move(kitas.Pavarde);
        Nd=move(kitas.Nd);
        Egz=move(kitas.Egz);
        gmediana=move(kitas.gmediana);
        gvidurkis=move(kitas.gvidurkis);

        kitas.Nd.clear(); kitas.Nd.shrink_to_fit();
        kitas.Vardas=kitas.Pavarde="";
        kitas.Egz=kitas.gmediana=kitas.gvidurkis=0;
    }
    return *this;
}

ostream &operator<<(ostream & output, studentas &k)
{
	output<< setiosflags(ios_base::left) << setw(20) << k.Pavarde <<
	setiosflags(ios_base::left) << setw(16) << k.Vardas <<"    "<<
	setiosflags(ios_base::left) << setw(16) << fixed << setprecision(2) << k.gvidurkis <<
    setiosflags(ios_base::left) << setw(16) << fixed << setprecision(2) << k.gmediana << endl;
	return output;
};

void studentas::failas (std::istream &is, int index) 
{
    is>>Pavarde>>Vardas;
    int paz, j=1;
    while (is>>paz)
    {
        Nd.push_back(paz);
        if (j==index-2) 
            {
                Egz=paz;
                Nd.pop_back(); 
            }
        j++;
    }
    galutinis();
    is.clear(); is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void studentas::galutinis()
{
    int suma=0, sz=Nd.size();
    for (auto &i:Nd)
    {suma=suma+i;}
    gvidurkis=(suma*1.0/sz)*0.4+(Egz*0.6);
   
    float mediana=0;
    sort(Nd.begin(), Nd.end());
    Nd.size()%2!=0? mediana=(Nd.at(sz/2))*1.0:mediana=((Nd.at(sz/2-1))+Nd.at(sz/2))/2.0;
    gmediana=mediana*0.4+Egz*0.6;
    ndclear();
}



//1-tik raides ir skaiciai>0
//2- tik skaiciai>0
//3 - 0<skaicius arba n
//4 - skaicius [0;10] arba n
//5- skaicius [0;10]
bool check(string &b, short int ch)
{
    try
    {
        if (ch==1)
        {
            getline(cin,b);
            if(b=="") {throw "Klaida. Įvedėte simbolį. ";}
            int i=0;
            const char* masyvas=b.c_str();
            while (masyvas[i])
            {
              if (!iswalnum(masyvas[i])||b=="") 
              { throw "Klaida. Įvedėte simbolį. ";
              break;}
              i++;
            }
            return true;
        }

        if(ch==2)
        {
            getline(cin,b);
            if (!all_of(b.begin(), b.end(), ::isdigit)||b=="0"||b=="") 
            {throw "Klaida. Įvedėte simbolį, raidę arba netinkamą skaičių. ";}
            return true;
        }

        if (ch==3)
        {
            getline(cin,b);
            if ((!all_of(b.begin(), b.end(), ::isdigit)&&b!="n"&&b!="N")||b=="0"||b=="")
            { throw "Klaida. Įvedėte simbolį, netinkamą raidę arba netinkamą skaičių. ";}
            return true;
        }

        if (ch==4)
        {
            getline(cin,b);
            if ((!all_of(b.begin(), b.end(), ::isdigit)&&b!="n"&&b!="N")||b=="")
            { throw "Klaida. Įvedėte simbolį, netinkamą raidę arba netinkamą skaičių. "; }

            else if (all_of(b.begin(), b.end(), ::isdigit)&&stoi(b)>10)
            { throw "Klaida. Įvedėte per didelį skaičių. ";}
            return true;
        }
        if (ch==5)
        {
            getline(cin,b);
            if(b=="") {throw "Klaida. Įvedėte simbolį, raidę arba netinkamą skaičių. ";}
            if (!all_of(b.begin(), b.end(), ::isdigit)||(all_of(b.begin(), b.end(), ::isdigit)&&stoi(b)>10))
            { throw "Klaida. Įvedėte simbolį, raidę arba netinkamą skaičių. "; }
            return true;
        }
    }
    catch(const char* er)
    { cout<<er; return false;}
    return false;
}

bool check(string q, string p, string &b)
{
    try
    {
        string h,j;
        getline(cin,b);
        h=char(q[0]-32);
        j=char(p[0]-32);
        if(b!=q&&b!=p&&b!=h&&b!=j) {throw "Klaida. Įvedėte skaičių, simbolį arba netinkamą raidę. ";}
        return true;
    }
    catch(const char* er)
    { cout<<er; return false; }
    return false;  
}

void pildyti(studentas &temp, string choice_1)
{
    string choice_2, a, info;
    Vector<int> pazymiai;
    bool b;
    do
    {
        cout<<"Jei norite visus studento duomenis įrašyti, spauskite 'i', o jei generuoti atsitiktinai - spauskite 'g'. ";
        b=check("i", "g", choice_2);
    } while (!b);
    if (choice_2=="i"||choice_2=="I")
    {
        string egz_paz;
        do{
        cout<<"Įveskite studento vardą: ";
        b=check(info,1);
        }while(!b);
        info[0]=toupper(info[0]);
        temp.vardas(info);

        do{
        cout<<"Įveskite studento pavardę: ";
        b=check(info,1);
        }while(!b);
        info[0]=toupper(info[0]);
        temp.pavarde(info);

        if (choice_1=="n"||choice_1=="N")
        {
            do
                {
                    cout<<"Įveskite studento namų darbų pažymius. Kai įvedėte visus pažymius, spauskite 'n'. "<<endl;
                    b=check(a,5);
                }while(!b);
                pazymiai.push_back(stoi(a));
            do
                {
                    b=false;
                    while(!b){ b=check(a,4);}
                    if(a=="n"||a=="N") {break;}
                    pazymiai.push_back(stoi(a));
                }while (a!="n"&&a!="N");
        }
        else
        {
            do
                {
                    cout<<"Įveskite studento namų darbų pažymius. Kai įvedėte visus pažymius, spauskite 'n'. "<<endl;
                    b=check(a,5);
                }while(!b);
                pazymiai.push_back(stoi(a));
            do
            {
                b=false;
                while(!b){ b=check(a,4);}
                if(a=="n"||a=="N") {break;}
                pazymiai.push_back(stoi(a));
            }while (pazymiai.size()<stoi(choice_1));
    
            if ((pazymiai.size())==stoi(choice_1))
            { cout<<choice_1<<" paž. įrašyti."<<endl; }
            
            if ((a=="n"||a=="N")&&(pazymiai.size())<stoi(choice_1))
            { for (int j=(pazymiai.size()); j<stoi(choice_1); j++) {pazymiai.push_back(0);}}
        }
        temp.nd(pazymiai);
        do{
        cout<<"Įveskite studento egzamino pažymį (0-10): ";
        b=check(egz_paz, 5);
        } while(!b);
        temp.egz(stoi(egz_paz));
        temp.galutinis();
    }
    else
    {
        string paz_kiek;
        std::random_device rd;
        std::mt19937 mt(rd());
        uniform_int_distribution<int> dist(0,10); //pazymiams
        uniform_int_distribution<int> pas(0,1); //gender
        uniform_int_distribution<int> v(0,99); //vardai
        short int a;
        if(pas(mt)==0)//mot
        {
            a=v(mt);
            temp.vardas(m_vardai[a]);
            uniform_int_distribution<int> v(0,42); //pavardes
            a=v(mt);
            if (a<=27) {temp.pavarde(pavardes[a]+"aite");}
            else if (a>27&&a<=39) {temp.pavarde(pavardes[a]+"iute");}
            else {temp.pavarde(pavardes[a]+"ute");}
        }
        else //vyr
        {
            a=v(mt);
            temp.vardas(v_vardai[a]);
            uniform_int_distribution<int> v(0,42); //pavardes
            a=v(mt);
            if (a<=28) {temp.pavarde(pavardes[a]+"as");}
            else if (a>28&&a<=38) {temp.pavarde(pavardes[a]+"ius");}
            else {temp.pavarde(pavardes[a]+"us");}
        }
        if (choice_1=="n"||choice_1=="N")
        {
            do
            {
                cout<<"Įveskite norimą pažymių kiekį: "; 
                b=check(paz_kiek, 2);
            }while(!b);
        for (int i=0; i<stoi(paz_kiek); i++) { pazymiai.push_back(dist(mt));}  
        }
        else
        {
            for (int i=0; i<stoi(choice_1); i++)
            {pazymiai.push_back(dist(mt));}
        }
        temp.nd(pazymiai);
        temp.egz(dist(mt));
        temp.galutinis();
    }
    temp.ndclear();
    cout<<"Duomenys įrašyti."<<endl;
}

bool rusiuoti(const studentas &a, const studentas &b)
{
    if (a.getpavarde()==b.getpavarde()) {return a.getvardas()<b.getvardas();}
    return a.getpavarde()<b.getpavarde();   
}

bool armaz(const studentas &a)
{ return (a.getvid()>=5||a.getmed()>=5);}

void failo_gen(int stud, int paz, string &pav)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    uniform_int_distribution<int> dist(0,10); //pazymiams
    uniform_int_distribution<int> pas(0,1); //gender
    uniform_int_distribution<int> v(0,43); //pavardes
    short int a,b;
    string f;
    
    cout<<"Įrašykite norimą failo pavadinimą: "; getline(cin,pav);
    if (pav.length()>5)
    {
        pav.find(".TXT")!=pav.npos? pav.erase(pav.length()-4):pav;
        pav.substr(pav.length()-4, 4)!=".txt"? pav=pav+".txt":pav;
    }
    else {pav=pav+".txt";}
    
    std::ofstream failas (pav);
    failas<<setw(20)<<left<<"Pavarde"<<setw(16)<<left<<"Vardas";
    for(int i=0; i<paz; i++)
    {
        failas<<"ND"<<setw(4)<<i+1;
    }
    failas<<setw(7)<<"Egz."<<endl;
    for (int i=0; i<stud; i++)
    {
        if (pas(mt)==0) //mot
        {
            a=v(mt);
            if (a<=27) {failas<<setw(20)<<left<<pavardes[a]+"aite";}
            else if (a>27&&a<=39) {failas<<setw(20)<<left<<pavardes[a]+"iute";}
            else {failas<<setw(20)<<left<<pavardes[a]+"ute";}
            uniform_int_distribution<int> v(0,99); //vardai
            a=v(mt);
            failas<<setw(16)<<left<<m_vardai[a];
        }
        else //vyr
        {
            a=v(mt);
            if (a<=27) {failas<<setw(20)<<left<<pavardes[a]+"as";}
            else if (a>27&&a<=39) {failas<<setw(20)<<left<<pavardes[a]+"ius";}
            else {failas<<setw(20)<<left<<pavardes[a]+"us";}
            uniform_int_distribution<int> v(0,99); //vardai
            a=v(mt);
            failas<<setw(16)<<left<<v_vardai[a];
        }
        for (int j=0; j<=paz; j++) { b=dist(mt); failas<<setw(6)<<b;}
        failas<<endl;
    }
    failas.close();
}

void vec_1(string f, bool ch)
{   
    duration<double> diff;
    Vector<studentas> grupe;
    Vector<studentas> grupe_1;
    Vector<studentas> grupe_2;
    Vector<int> pazymiai;
    studentas laikinas;
    int a;
    string x, z, info; 
    short int y=0, index=0;
    auto start = high_resolution_clock::now(); //--------------------------
    ifstream data (f); 
    getline(data,x); stringstream eilut(x);
    while (eilut>>z)
    {
        y++;
        if (z.front()=='E'||z.front()=='e') {index=y;}
    } 
    index==0? index=y:index;
    while (getline(data,x))
    {
       stringstream eilute(x);
       laikinas.failas(eilute, index); 
       grupe.push_back(laikinas);
       laikinas.ndclear();
    }
    data.close(); 
    if(ch==0) 
    {
        std::sort (grupe.begin(), grupe.end(), rusiuoti); 
        cout<<left<<setw(20)<<"Pavardė"<<left<<setw(16)<<"Vardas"<<setw(18)<<"Galutinis(Vid.)"<<setw(18)<<"Galutinis(Med.)"<<endl;
        cout<<string(68, '-')<<"\n";
        for (auto &i:grupe)
        {cout<<i;}
        exit(0);
    }
    else
    {
        a=grupe.size();
        auto e1 = high_resolution_clock::now(); //--------------------------
        auto it=std::partition(grupe.begin(), grupe.end(), armaz);
        std::copy(grupe.begin(), it, std::back_inserter(grupe_1));
        std::copy(it, grupe.end(), std::back_inserter(grupe_2));
        grupe.clear(); grupe.shrink_to_fit();
        auto e2=high_resolution_clock::now(); //--------------------------
        std::sort(grupe_1.begin(), grupe_1.end(), rusiuoti);
        std::sort(grupe_2.begin(), grupe_2.end(), rusiuoti); 
        auto e3 = high_resolution_clock::now(); //--------------------------
        isvedimas(grupe_1, grupe_2, 0 );
        grupe_1.shrink_to_fit(); grupe_2.shrink_to_fit();
        auto e4 = high_resolution_clock::now(); //--------------------------
        diff=e1-start; cout<<a<<" įrašų failo nuskaitymo ir galutinių pažymių skaičiavimo laikas: "<<diff.count()<<" s\n";
        diff=e2-e1; cout<<a<<" įrašų failo dalijimo į dvi grupes laikas: "<<diff.count()<<" s\n";
        diff=e3-e2; cout<<a<<" įrašų failo rūšiavimo abėcėlės tvarka laikas: "<<diff.count()<<" s\n";
        diff=e4-e3; cout<<"Grupių 'protingieji' ir 'vargsai' įrašymo į failus laikas: "<<diff.count()<<" s\n";
        auto end = high_resolution_clock::now(); //--------------------------
        diff=end-start; cout<<a<<" įrašų testo laikas: "<<diff.count()<<" s\n";  
    }  
}  

void list_1(string f)
{
    duration<double> diff;
    list<studentas> grupe;
    list<studentas> grupe_1;
    list<studentas> grupe_2;
    Vector<int> pazymiai;
    studentas laikinas;
    int a;
    string x,z, info;
    short int y=0, index=0;
    auto start = high_resolution_clock::now(); //--------------------------
    ifstream data (f);
    getline(data,x);
    stringstream eilut(x);
    while (eilut>>z)
    {
        y++;
        if (z.front()=='E'||z.front()=='e') {index=y;}
    }
    index==0? index=y:index;
    while (getline(data,x))
    {
       stringstream eilute(x);
       laikinas.failas(eilute, index); 
       grupe.push_back(laikinas);
       laikinas.ndclear();
    }
    data.close(); 

    a=grupe.size();
    auto e1 = high_resolution_clock::now(); //--------------------------
    auto it=std::partition(grupe.begin(), grupe.end(), armaz);
    std::copy(grupe.begin(), it, std::back_inserter(grupe_1));
    std::copy(it, grupe.end(), std::back_inserter(grupe_2));
    grupe.clear();
    auto e2=high_resolution_clock::now(); //--------------------------
    grupe_1.sort(rusiuoti);
    grupe_2.sort(rusiuoti); 
    auto e3 = high_resolution_clock::now(); //--------------------------
    isvedimas(grupe_1, grupe_2, 0);
    auto e4 = high_resolution_clock::now(); //--------------------------
    diff=e1-start; cout<<a<<" įrašų failo nuskaitymo ir galutinių pažymių skaičiavimo laikas: "<<diff.count()<<" s\n";
    diff=e2-e1; cout<<a<<" įrašų failo dalijimo į dvi grupes laikas: "<<diff.count()<<" s\n";
    diff=e3-e2; cout<<a<<" įrašų failo rūšiavimo abėcėlės tvarka laikas: "<<diff.count()<<" s\n";
    diff=e4-e3; cout<<"Grupių 'protingieji' ir 'vargsai' įrašymo į failus laikas: "<<diff.count()<<" s\n";
    auto end = high_resolution_clock::now(); //--------------------------
    diff=end-start; cout<<a<<" įrašų testo laikas: "<<diff.count()<<" s\n";   
}

void deque_1(string f)
{   
    duration<double> diff;
    deque<studentas> grupe;
    deque<studentas> grupe_1;
    deque<studentas> grupe_2;
    Vector<int> pazymiai;
    studentas laikinas;
    int a;
    string x,z, info;
    short int y=0, index=0;
    auto start = high_resolution_clock::now(); //--------------------------
    ifstream data (f);
    getline(data,x);
    stringstream eilut(x);
    while (eilut>>z)
    {
        y++;
        if (z.front()=='E'||z.front()=='e') {index=y;}
    }
    index==0? index=y:index;
     while (getline(data,x))
    {
       stringstream eilute(x);
       laikinas.failas(eilute, index); 
       grupe.push_back(laikinas);
       laikinas.ndclear();
    }
    data.close(); 
    a=grupe.size();
    auto e1 = high_resolution_clock::now(); //--------------------------
    auto it=std::partition(grupe.begin(), grupe.end(), armaz);
    std::copy(grupe.begin(), it, std::back_inserter(grupe_1));
    std::copy(it, grupe.end(), std::back_inserter(grupe_2));
    grupe.clear(); grupe.shrink_to_fit();
    auto e2=high_resolution_clock::now(); //--------------------------
    sort(grupe_1.begin(), grupe_1.end(), rusiuoti);
    sort(grupe_2.begin(), grupe_2.end(), rusiuoti); 
    auto e3 = high_resolution_clock::now(); //--------------------------
    isvedimas(grupe_1, grupe_2, 0);
    grupe_1.shrink_to_fit(); grupe_2.shrink_to_fit();
    auto e4 = high_resolution_clock::now(); //--------------------------
    diff=e1-start; cout<<a<<" įrašų failo nuskaitymo ir galutinių pažymių skaičiavimo laikas: "<<diff.count()<<" s\n";
    diff=e2-e1; cout<<a<<" įrašų failo dalijimo į dvi grupes laikas: "<<diff.count()<<" s\n";
    diff=e3-e2; cout<<a<<" įrašų failo rūšiavimo abėcėlės tvarka laikas: "<<diff.count()<<" s\n";
    diff=e4-e3; cout<<"Grupių 'protingieji' ir 'vargsai' įrašymo į failus laikas: "<<diff.count()<<" s\n";
    auto end = high_resolution_clock::now(); //---------------------------------
    diff=end-start; cout<<a<<" įrašų testo laikas: "<<diff.count()<<" s\n";   
}

void vec_2(string f)
{
    duration<double> diff;
    Vector<studentas> grupe_1;
    Vector<studentas> grupe_2;
    Vector<int> pazymiai;
    studentas laikinas;
    int a;
    string x, z, info; 
    short int y=0, index=0;
    auto start = high_resolution_clock::now();//---------------------------------
    ifstream data (f);
    getline(data,x);
    stringstream eilut(x);
    while (eilut>>z)
    {
        y++;
        if (z.front()=='E'||z.front()=='e') {index=y;}
    }
    index==0? index=y:index;
     while (getline(data,x))
    {
       stringstream eilute(x);
       laikinas.failas(eilute, index); 
       grupe_1.push_back(laikinas);
       laikinas.ndclear();
    }
    data.close(); 
    a=grupe_1.size();
    auto e1 = high_resolution_clock::now(); //--------------------------
    auto it=std::partition(grupe_1.begin(), grupe_1.end(), armaz) ;
    grupe_2.reserve(std::distance(it, grupe_1.end()));
    std::copy(it, grupe_1.end(), std::back_inserter(grupe_2));
    grupe_1.erase(it, grupe_1.end()); grupe_1.shrink_to_fit();
    auto e2=high_resolution_clock::now(); //--------------------------
    std::sort(grupe_1.begin(), grupe_1.end(), rusiuoti);
    std::sort(grupe_2.begin(), grupe_2.end(), rusiuoti); 
    auto e3 = high_resolution_clock::now(); //--------------------------
    isvedimas(grupe_1, grupe_2, 1);
    grupe_1.shrink_to_fit();
    grupe_2.shrink_to_fit();
    auto e4 = high_resolution_clock::now(); //--------------------------
    diff=e1-start; cout<<a<<" įrašų failo nuskaitymo ir galutinių pažymių skaičiavimo laikas: "<<diff.count()<<" s\n";
    diff=e2-e1; cout<<a<<" įrašų failo dalijimo į dvi grupes laikas: "<<diff.count()<<" s\n";
    diff=e3-e2; cout<<a<<" įrašų failo rūšiavimo abėcėlės tvarka laikas: "<<diff.count()<<" s\n";
    diff=e4-e3; cout<<"Grupių 'protingieji' ir 'vargsai' įrašymo į failus laikas: "<<diff.count()<<" s\n";
    auto end = high_resolution_clock::now(); //--------------------------
    diff=end-start; cout<<a<<" įrašų testo laikas: "<<diff.count()<<" s\n";    
}

void list_2(string f)
{
    duration<double> diff;
    list<studentas> grupe_1;
    list<studentas> grupe_2;
    studentas laikinas;
    Vector<int> pazymiai;
    int a;
    string x, z, info; 
    short int y=0, index=0;
    auto start = high_resolution_clock::now();//---------------------------------
    ifstream data (f);
    getline(data,x);
    stringstream eilut(x);
    while (eilut>>z)
    {
        y++;
        if (z.front()=='E'||z.front()=='e') {index=y;}
    }
    index==0? index=y:index;
     while (getline(data,x))
    {
       stringstream eilute(x);
       laikinas.failas(eilute, index); 
       grupe_1.push_back(laikinas);
       laikinas.ndclear();
    }
    data.close(); 
    a=grupe_1.size();
    auto e1 = high_resolution_clock::now(); //---------------------------------
    auto it=std::partition(grupe_1.begin(), grupe_1.end(), armaz) ;
    std::copy(it, grupe_1.end(), std::back_inserter(grupe_2));
    grupe_1.erase(it, grupe_1.end());
    auto e2=high_resolution_clock::now(); //---------------------------------
    grupe_1.sort(rusiuoti);
    grupe_2.sort(rusiuoti); 
    auto e3 = high_resolution_clock::now(); //---------------------------------
    isvedimas(grupe_1, grupe_2, 1);
    auto e4 = high_resolution_clock::now(); //---------------------------------
    diff=e1-start; cout<<a<<" įrašų failo nuskaitymo ir galutinių pažymių skaičiavimo laikas: "<<diff.count()<<" s\n";
    diff=e2-e1; cout<<a<<" įrašų failo dalijimo į dvi grupes laikas: "<<diff.count()<<" s\n";
    diff=e3-e2; cout<<a<<" įrašų failo rūšiavimo abėcėlės tvarka laikas: "<<diff.count()<<" s\n";
    diff=e4-e3; cout<<"Grupių 'protingieji' ir 'vargsai' įrašymo į failus laikas: "<<diff.count()<<" s\n";
    auto end = high_resolution_clock::now(); //---------------------------------
    diff=end-start; cout<<a<<" įrašų testo laikas: "<<diff.count()<<" s\n";     
}

void deque_2 (string f)
{
    duration<double> diff;
    deque<studentas> grupe_1;
    deque<studentas> grupe_2;
    Vector<int> pazymiai;
    studentas laikinas;
    int a;
    string x, z, info; 
    short int y=0, index=0;
    auto start = high_resolution_clock::now();//---------------------------------
    ifstream data (f);
    getline(data,x);
    stringstream eilut(x);
    while (eilut>>z)
    {
        y++;
        if (z.front()=='E'||z.front()=='e') {index=y;}
    }
    index==0? index=y:index;
     while (getline(data,x))
    {
       stringstream eilute(x);
       laikinas.failas(eilute, index); 
       grupe_1.push_back(laikinas);
       laikinas.ndclear();
    }
    data.close(); 
    a=grupe_1.size();
    auto e1 = high_resolution_clock::now(); //---------------------------------
    auto it=std::partition(grupe_1.begin(), grupe_1.end(), armaz) ;
    std::copy(it, grupe_1.end(), std::back_inserter(grupe_2));
    grupe_1.erase(it, grupe_1.end());
    auto e2=high_resolution_clock::now(); //---------------------------------
    sort(grupe_1.begin(), grupe_1.end(), rusiuoti);
    sort(grupe_2.begin(), grupe_2.end(), rusiuoti); 
    auto e3 = high_resolution_clock::now(); //---------------------------------
    isvedimas(grupe_1, grupe_2, 1);
    grupe_1.shrink_to_fit(); grupe_2.shrink_to_fit();
    auto e4 = high_resolution_clock::now(); //---------------------------------
    diff=e1-start; cout<<a<<" įrašų failo nuskaitymo ir galutinių pažymių skaičiavimo laikas: "<<diff.count()<<" s\n";
    diff=e2-e1; cout<<a<<" įrašų failo dalijimo į dvi grupes laikas: "<<diff.count()<<" s\n";
    diff=e3-e2; cout<<a<<" įrašų failo rūšiavimo abėcėlės tvarka laikas: "<<diff.count()<<" s\n";
    diff=e4-e3; cout<<"Grupių 'protingieji' ir 'vargsai' įrašymo į failus laikas: "<<diff.count()<<" s\n";
    auto end = high_resolution_clock::now(); //---------------------------------
    diff=end-start; cout<<a<<" įrašų testo laikas: "<<diff.count()<<" s\n";    
}

template <typename T> void isvedimas( T&grupe_1, T&grupe_2, bool st)
{
    string p,v;
    if (std::is_same<T, Vector<studentas> >::value)
    {
        if (st==0) {p="protingieji(v1).txt"; v="vargsai(v1).txt";}
        else {p="protingieji(v2).txt"; v="vargsai(v2).txt";}
    }
    else if (std::is_same<T, list<studentas> >::value)
    {
        if(st==0){p="protingieji(l1).txt"; v="vargsai(l1).txt";}
        else {p="protingieji(l2).txt"; v="vargsai(l2).txt";}
    }
    else
    {
        if(st==0) {p="protingieji(d1).txt"; v="vargsai(d1).txt";}
        else {p="protingieji(d2).txt"; v="vargsai(d2).txt";}
    }

    ofstream rez1(p);
    rez1<<setw(20)<<left<<"Pavarde"<<setw(16)<<left<<"Vardas"<<setw(16)<<left<<"Galutinis(Vid.)"<<setw(16)<<left<<"Galutinis(Med.)"<<endl; 
    
    for (auto &j:grupe_1)
    { rez1<<j;}
    grupe_1.clear(); 

    ofstream rez2(v);
    rez2<<setw(20)<<left<<"Pavarde"<<setw(16)<<left<<"Vardas"<<setw(16)<<left<<"Galutinis(Vid.)"<<setw(16)<<left<<"Galutinis(Med.)"<<endl;
    for (auto &k:grupe_2)
    { rez2<<k;} 
    grupe_2.clear(); 
}