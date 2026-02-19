//#include <iostream>
//using namespace std;
//
//
//class Book {
//public:
//    string title;
//    string author;
//    string publisher;
//
//    Book(string t, string a, string p) {
//        title = t;
//        author = a;
//        publisher = p;
//    }
//
//    void display() {
//        cout << "Title: " << title << endl;
//        cout << "Author: " << author << endl;
//        cout << "Publisher: " << publisher << endl;
//    }
//};
//
//
//class FictionBook : public Book {
//public:
//    string genre;
//    string protagonist;
//
//    FictionBook(string t, string a, string p, string g, string pro): Book(t, a, p)
//    {
//        genre = g;
//        protagonist = pro;
//    }
//
//    void display() {
//        Book::display();
//        cout << "Genre: " << genre << endl;
//        cout << "Protagonist: " << protagonist << endl;
//    }
//};
//
//
//int main() {
//    string bookname;
//    cout << "enter name of book ";
//    cin >> bookname;
//
//    string authorname;
//    cout << "enter name of author ";
//    cin >> authorname;
//    string publishername;
//    cout << "enyer the name of publisher ";
//    cin >> publishername;
//
//    string genre;
//    cout << "enyer the name of genre ";
//    cin >> genre;
//
//    string protagonist;
//    cout << "enyer the protagonist ";
//    cin >> protagonist;
//
//    FictionBook f1(bookname, authorname, publishername, genre, protagonist);
//
//    f1.display();
//
//    return 0;
//}
