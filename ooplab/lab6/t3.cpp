// ACCORDING TO SIR TALOOT


#include <iostream>
#include <string>
using namespace std;
class Cloudstorage{
public:
virtual void uploadfile(string filename)=0;
virtual void downloadfile(string filename)=0;
virtual void deletefile(string filename)=0;
virtual void listfiles(string filename)=0;

};
class AWSStorage : public Cloudstorage{
    public:
    void uploadfile(string filename) override{
        cout << " Uploading " << filename << " to AWS S3... Done. " << endl;
    }
    void downloadfile(string filename) override{
        cout << " Downloading " << filename << " from AWS S3... Done." << endl;
    }
    void deletefile(string filename) override{
        cout << " Deleting " << filename << " from AWS S3... Done." << endl;
    }
    void listfiles(string filename) override{
        cout << " Listing files!!!!"  <<  endl;
    }
};
class GoogleDrivestorage : public Cloudstorage{
    public:
    void uploadfile(string filename) override{
        cout << " Uploading " << filename << " to  Googledrive... Done. " << endl;
    }
    void downloadfile(string filename) override{
        cout << " Downloading " << filename << " from Googledrive... Done." << endl;
    }
    void deletefile(string filename) override{
        cout << " Deleting " << filename << " from Googledrive... Done." << endl;
    }
    void listfiles(string filename) override{
        cout << " Listing files!!!!"  <<  endl;
    }
};
class Dropboxstorage : public Cloudstorage{
    public:
    void uploadfile(string filename) override{
        cout << " Uploading " << filename << " to  Dropbox... Done. " << endl;
    }
    void downloadfile(string filename) override{
        cout << " Downloading " << filename << " from Dropbox... Done." << endl;
    }
    void deletefile(string filename) override{
        cout << " Deleting " << filename << " from Dropbox... Done." << endl;
    }
    void listfiles(string filename) override{
        cout << " Listing files!!!!"  <<  endl;
    }
};
class OneDrivestorage : public Cloudstorage{
    public:
    void uploadfile(string filename) override{
        cout << " Uploading " << filename << " to  Onedrive... Done. " << endl;
    }
    void downloadfile(string filename) override{
        cout << " Downloading " << filename << " from Onedrive... Done." << endl;
    }
    void deletefile(string filename) override{
        cout << " Deleting " << filename << " from Onedrive... Done." << endl;
    }
    void listfiles(string filename) override{
        cout << " Listing files!!!!"  <<  endl;
    }   
};
int main(){
   Cloudstorage* AWS = new AWSStorage();
   AWS->uploadfile("Siuuu.docx");
   AWS->downloadfile("Siuuu.docx");
   AWS->deletefile("SIuuu.docx");
   AWS->listfiles("Siuui.docx");
   delete AWS;
     Cloudstorage* dr = new GoogleDrivestorage();
   dr->uploadfile("Meowww.pdf");
   dr->downloadfile("Meoow.pdf");
   dr->deletefile("Meoww.pdf");
   dr->listfiles("Meoww.pdf");
   delete dr;
     Cloudstorage* dro = new Dropboxstorage();
   dro->uploadfile("cr7.jpg");
   dro->downloadfile("cr7.jpg");
   dro->deletefile("cr7.jpg");
   dro->listfiles("cr7.jpg");
   delete dro;
     Cloudstorage* one = new OneDrivestorage();
   one->uploadfile("Lm10.img");
   one->downloadfile("Lm10.img");
   one->deletefile("Lm10.img");
   one->listfiles("Lm10.img");
   delete one;
   return 0;
}


