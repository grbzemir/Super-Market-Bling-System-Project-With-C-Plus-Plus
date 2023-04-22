#include<iostream>
#include<fstream>

using namespace std;

class shopping

{

   private:
   int urunkodu; // ürün kodu
   float price; // fiyat
   float dis; // indirimli fiyat

   string urunadi;

   public:

   void menu();
   void admin();
   void buyer();
   void add();
   void edit();
   void rem(); // silme
   void list();
   void receipt();

};


void shopping::menu()

{
   
   m:
   int secim;
   string email;
   string sifre;

   cout<<"\t\t\t_______________________________________________\n";
   cout<<"\t\t\t                                               \n";
   cout<<"\t\t\t            SUPERMARKET MAIN MENU              \n";
   cout<<"\t\t\t                                               \n";
   cout<<"\t\t\t_______________________________________________\n";
   cout<<"\t\t\t|                                              |\n";
   cout<<"\t\t\t|            1-ADMIN                           |\n";
   cout<<"\t\t\t|                                              |\n";
   cout<<"\t\t\t|            2-BUYER                           |\n";
   cout<<"\t\t\t|                                              |\n";
   cout<<"\t\t\t|            3-EXIT                            |\n";
   cout<<"\t\t\t|                                              |\n";
   cout<<"\t\t\t lutfen Secim Yapiniz: \n";
   cin>>secim;

    switch(secim)
    
    {

    case 1:

    cout<<"\t\t\t Lutfen Giris Yapiniz: \n";
    cout<<"\t\t\t Email Girisi: \n";
    cin>>email;
    cout<<"\t\t\t Sifre Girisi: \n";
    cin>>sifre;

    if(email=="kendihesabiniz@gmail.com" && sifre=="200323")

    {

        admin();

    }

    else

    {

        cout<<"\t\t\t Yanlis Giris Yaptiniz! \n";
        goto m;
        
    }

    break;

    

    
    case 2:
            buyer();
            break;

        case 3:
            exit(0);
            break;

        default:
            cout << "\t\t\t Yanlis Secim Yaptiniz! \n";
            goto m;
            break;
    }
    
}
   void shopping::admin()

   {
    
    m:
    int secim;
    cout<<"\n\n\n\t\t\t Admin Menu \n";
    cout<<"\n\t\t\t|________[1] Urun Ekle________|\n";
    cout<<"\n\t\t\t|________[2] Urun Duzenle________|\n";
    cout<<"\n\t\t\t|________[3] Urun Sil____|\n";
    cout<<"\n\t\t\t|________[4] Menuye Geri Don____|\n";

    cout<<"\n\n\t Lutfen Secim Yapiniz: ";
    cin>>secim;

    switch(secim)

    {

    case 1:
          add();
            break;

    case 2:
            edit();
                break;
    
    case 3:
            rem();
                break;

    case 4:
            menu();
                break;

    default:

    cout<<" Yanlis Secim Yaptiniz! ";

    }

    goto m;

    }

    void shopping::buyer()

    {
    
     m:
     int secim;
     cout<<"\t\t\t       Buyer         \n";
     cout<<"\t\t\t_____________________\n";
     cout<<"                           \n";
     cout<<"\t\t\t [1] Urun Al         \n";
     cout<<"                           \n";
     cout<<"\t\t\t [2] Menuye Geri Don \n";
     cout<<"\t\t\t Secimini Giriniz:   \n";

     cin>>secim;

        switch(secim)
    
        {

            case 1:
                receipt();
                break;

            case 2:
                menu();
                break;

            default:

            cout<<" Yanlis Secim Yaptiniz! ";

        }

        goto m;

    }

    void shopping::add()

    {
        
        m:
        fstream data;
        int c; // ürün kodu
        int token=0; 
        float p; // fiyat
        float d; // indirimli fiyat
        string n; // ürün adı

        cout<<"\n\n\t\t\t Urun Ekleme ";
        cout<<"\n\n\t Urun Kodu: ";
        cin>>urunkodu;
        cout<<"\n\t Urun Adi: ";
        cin>>urunadi;
        cout<<"\n\t Urun Fiyati: ";
        cin>>price;
        cout<<"\n\t Urun Indirimi: ";
        cin>>dis;

        data.open("database.txt",ios::in);
        
        if(!data)

        {

            data.open("database.txt",ios::out);
            data<<urunkodu<<" "<<urunadi<<" "<<price<<" "<<dis<<endl;
            data.close();

        }

        else

        {

            data>>c>>n>>p>>d;

            while(!data.eof()) //dosya sonuna kadar oku ama eşit olmicak

            {

                if(c==urunkodu)

                {

                    token++;

                }

                data>>c>>n>>p>>d;
            }

            data.close();

         
         if(token==1)

         goto m;

         else

         {
                
                data.open("database.txt",ios::app);
                data<<urunkodu<<" "<<urunadi<<" "<<price<<" "<<dis<<endl;
                data.close();
    
            
         }

        }

        cout<<"\n\n\t\t\t Urun Eklendi! \n";

    }

void shopping::edit()

{

    fstream data;
    fstream data1;

    int pkey; // ürün anahtari
    int token;
    token=0;
    int c;  // ürün kodu
    float p;  // fiyat
    float d; // indirimli fiyat
    string n; // ürün adı

    cout<<"\n\t\t\t Urun Kaydi Degistirme ";
    cout<<"\n\n\t Urun Kodu: ";
    cin>>pkey;

    data.open("database.txt",ios::in);

    if (!data)

    {

        cout<<"\n\t\t\t Urun Bulunamadi! \n";
        
    }
    

    else

    {

        data1.open("database1.txt",ios::out);
        data>>urunkodu>>urunadi>>price>>dis;

        while(!data.eof())

        {
            if (pkey==urunkodu)

            {

                cout<<"\n\t\t Yeni Urun Kodu: ";
                cin>>c;
                cout<<"\n\t\t Urun Adi: ";
                cin>>n;
                cout<<"\n\t\t Urun Fiyati: ";
                cin>>p;
                cout<<"\n\t\t Urun Indirimi: ";
                cin>>d;
                data1<<c<<" "<<n<<" "<<p<<" "<<d<<endl;
                cout<<"\n\t\t\t Urun Degistirildi! \n";
                token++;
                
            }

            else

            {

                data1<<urunkodu<<" "<<urunadi<<" "<<price<<" "<<dis<<endl;
                
            }

            data>>urunkodu>>urunadi>>price>>dis;
        }

        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)

        {

            cout<<"\n\t\t\t Urun Bulunamadi! \n";
            
        }
        
    }

}


void shopping::rem()

{
    fstream data,data1;
    int pkey;
    int token;
    token=0;
    cout<<"\n\n\t Urun Silme ";
    cout<<"\n\n\t Urun Kodu: ";
    cin>>pkey;

    data.open("database.txt",ios::in);

    if (!data)

    {

        cout<<"\n\t\t\t Dosya Bulunamadi! \n";
        
    }

    else

    {

        data1.open("database1.txt",ios::out);
        data>>urunkodu>>urunadi>>price>>dis;

        while(!data.eof())

        {

            if (urunkodu==pkey)

            {

                cout<<"\n\t\t\t Urun Silindi! \n";
                token++;
                
            }

            else

            {

                data1<<urunkodu<<" "<<urunadi<<" "<<price<<" "<<dis<<endl;
                
                
            }

            data>>urunkodu>>urunadi>>price>>dis;

        }

        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)

        {

            cout<<"\n\t\t\t Urun Bulunamadi! \n";
            
        }
    }

}


void shopping::list()

{
    
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|_______________________________________________________________\n";
    cout<<"Urun Kodu\tUrun Adi\tUrun Fiyati\n";
    cout<<"|_______________________________________________________________\n";
    data>>urunkodu>>urunadi>>price>>dis;

    while(!data.eof())

    {

        cout<<urunkodu<<"\t\t"<<urunadi<<"\t\t"<<price<<"\n";
        data>>urunkodu>>urunadi>>price>>dis;

    }

    data.close();


}

  void shopping::receipt()

  {
     
     fstream data;

     int arrc[100]; // birdan fazla degişkeni array ile tek seferde tuttuk
     int arrq[100];

     char secim;
     int c;
     c=0;
     float bakiye;
     bakiye=0;
     float dis;
     dis=0;
     float toplam;
     toplam=0;

     cout<<"\n\n\t\t\t\t Receipt ";
     
     data.open("database.txt",ios::in);

     if(!data)
     
     {

        cout<<"\n\t\t\t Bos Dosya ! \n";

     }

     else

     {

        data.close();

        list();
        cout<<"\n_______________________________________________________________\n";
        cout<<"\n|                                                              \n";
        cout<<"n                          LUTFEN SIPARISINIZI GIRINIZ           \n";
        cout<<"\n|                                                              \n";  
        cout<<"\n_______________________________________________________________\n";

     

     do
     
     {
        
        m:
        cout<<"\n\t Urun Kodu: ";
        cin>>arrc[c]; // kod
        cout<<"\n\t Urun Adedi: ";
        cin>>arrq[c]; // adet

        

        for ( int i = 0; i < c; i++)

        {
            if (arrc[c]==arrc[i])

            {
                cout<<"\n\t\t\t Ayni Urunu Tekrar Giremezsiniz! \n";
                goto m;
                
            }
            
        }

        c++;
        cout<<"\n\n Devam Etmek Ister Misiniz? devam etmek istiyorsaniz y'ye basiniz";
        cin>>secim;

     }

     while(secim =='y');
      
	
     cout<<"\n\n\t\t\t______________________Receipt_________________\n";
     cout<<"\n\t\t\tUrun Kodu\tUrun Adi\tUrun Fiyati\tAdet\tToplam\n";
    

     for(int i=0;i<c;i++)

     {

        data.open("database.txt",ios::in);
        data>>urunkodu>>urunadi>>price>>dis;

        while (!data.eof())

        {

            if(urunkodu==arrc[i])

            {

                bakiye=price*arrq[i];
                dis=bakiye-(bakiye*dis/100);
                toplam+=dis;
                cout<<"\n\t\t\t"<<urunkodu<<"\t\t"<<urunadi<<"\t\t"<<price<<"\t\t"<<bakiye<<"\t\t"<<arrq[i]<<"\t"<<dis<<"\n";

            }

            data>>urunkodu>>urunadi>>price>>dis;
            
        }

     }

       data.close();

  }

  cout<<"\n\n___________________________________________";
  cout<<"\n\t\t\t Toplam Tutar: "<<toplam<<"\n";

  }

  int main()

  {
    
    system("color 4");
    shopping s;
    s.menu();

  }



   
