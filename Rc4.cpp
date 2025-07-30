/// Code for reading data from different files and taking average
/// This code and the files should in the same folder
/// Files name spelling should be accurate

#include<bits/stdc++.h>
using namespace std;

 int main ()
 {
	
     ifstream fin;

     fin.open("c2_n.dat"); ///Put your desired file name in the " "

     if (!fin.is_open())
     {
         cout<< "file couldn't be opened"<<endl; ///Checking if the file is open or not
         exit(1);
     }

     double a,b,c,d,e,f,g,h; ///Take no of variables same as your column (if file has 4 column take 4 variables)

     vector<double> a_1; ///you can also take array
     vector<double> b_1; /// I need the data of just two columns so therefore two vectors or array
     vector<double> c_1; ///you can also take array
     vector<double> d_1; /// I need the data of just two columns so therefore two vectors or array
     vector<double> e_1; ///you can also take array
     vector<double> f_1; /// I need the data of just two columns so therefore two vectors or array
     vector<double> g_1; ///you can also take array
     vector<double> h_1; /// I need the data of just two columns so therefore two vectors or array


        while (!fin.eof())
        {
            fin >>a>>b>>c>>d>>e>>f>>g>>h; /// data of column 1 will be stored in variable a , column 2 will be in c and so on
            a_1.push_back(a); ///storing the datas in vectors
            b_1.push_back(b);
            c_1.push_back(c); ///storing the datas in vectors
            d_1.push_back(d);
            e_1.push_back(e); ///storing the datas in vectors
            f_1.push_back(f);
            g_1.push_back(g); ///storing the datas in vectors
            h_1.push_back(h);
        }
        

     fin.close();

        ofstream fout;
     fout.open ("c2_nnew.dat");/// output file

     vector <double> a_f;
	 vector <double> b_f;
     vector <double> c_f;
     vector <double> d_f;
     vector <double> e_f;
     vector <double> f_f;
     vector <double> g_f;
     vector <double> h_f;

     double af;
	 double bf;
     double cf;
     double df;
     double ef;
     double ff;
     double gf;
     double hf;

        for (int j=0; j<a_1.size();j++)

        {   af= (a_1[j]);
	        bf= (b_1[j]);
            cf= (c_1[j]);
            df= (d_1[j]);
            ef= log(e_1[j]);
            ff= log(f_1[j]);
            gf= log(g_1[j]);
            hf= log(h_1[j]);

            a_f.push_back(af);
	        b_f.push_back(bf);
            c_f.push_back(cf);
            d_f.push_back(df);
            e_f.push_back(ef);
            f_f.push_back(ff);
            g_f.push_back(gf);
            h_f.push_back(hf);

            fout << a_f[j]<<'\t'<< b_f[j]<<'\t'<<c_f[j]<<'\t'<< d_f[j]<<'\t'<<e_f[j]<<'\t'<< f_f[j]<<'\t'<<g_f[j]<<'\t'<<h_f[j]<<endl;
        }

     return 0;

     /* in this code only two files being used for taking average . you can also take multiple files ,
     just copy the above lines where files being read and expand the code with same procedure. */
 } 
