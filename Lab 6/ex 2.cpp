#include <iostream>

using namespace std;

class BookSeries    // clasa de baza
{
private:
    string author;
    string genre;

public:
    string title;
    int page_number;
    int price;

    virtual void particular_details()
    {
        title = "The Lord of the Rings";
        page_number = 1365;
        price = 130;
    }

    friend void show_details(BookSeries book);
    friend class GeneralDetails;
};

class GeneralDetails    // friend class pentru BookSeries; seteaza datele generale pe care le au toate cartile in comun
{
public:
    void general_details(BookSeries *book)
    {
        book->author = "J. R. R. Tolkien";
        book->genre = "Fantasy";
    }
};

class Book1 : public BookSeries     // seteaza datele particulare pentru prima carte
{
public:
    void particular_details()
    {
        title = "The Fellowship of the Ring";
        page_number = 448;
        price = 42;
    }

    friend class TransferDetails;
};

class Book2 : public BookSeries     // seteaza datele particulare pentru a doua carte
{
public:
    void particular_details()
    {
        title = "The Two Towers";
        page_number = 464;
        price = 45;
    }

    friend class TransferDetails;
};

class Book3 : public BookSeries     // seteaza datele particulare pentru a treia carte
{
public:
    void particular_details()
    {
        title = "The Return of the King";
        page_number = 453;
        price = 43;
    }

    friend class TransferDetails;
};

class TransferDetails    // friend class pentru clasele Book1, Book2, Book3;
{                        // transfera detaliile particulare din obiectele de tip Book1, Book2, Book3 intr-un obiect de tip BookSeries
public:
    void transfer_details(BookSeries *book, string ttl, int pg, int pr)
    {
        book->title = ttl;
        book->page_number = pg;
        book->price = pr;
    }
};

void show_details(BookSeries book)     // afisare pentru un obiect de tip BookSeries
{
    cout << "Title: "<< book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "Number of pages: " << book.page_number << endl;
    cout << "Genre: " << book.genre << endl;
    cout << "Price: " << book.price << endl;
    cout << endl;
}

int main()
{
    cout << "---Book Series---" << endl;
    BookSeries series;
    GeneralDetails series_gen;

    series.particular_details();
    series_gen.general_details(&series);
    show_details(series);

    //

    cout << "---Volume 1---" << endl;
    Book1 book1;
    TransferDetails book1_tran;
    BookSeries book1_gen;
    GeneralDetails book1_det;

    book1.particular_details();
    book1_tran.transfer_details(&book1_gen, book1.title, book1.page_number, book1.price);
    book1_det.general_details(&book1_gen);
    show_details(book1_gen);

    //

    cout << "---Volume 2---" << endl;
    Book2 book2;
    TransferDetails book2_tran;
    BookSeries book2_gen;
    GeneralDetails book2_det;

    book2.particular_details();
    book2_tran.transfer_details(&book2_gen, book2.title, book2.page_number, book2.price);
    book2_det.general_details(&book2_gen);
    show_details(book2_gen);

    //

    cout << "---Volume 3---" << endl;
    Book3 book3;
    TransferDetails book3_tran;
    BookSeries book3_gen;
    GeneralDetails book3_det;

    book3.particular_details();
    book3_tran.transfer_details(&book3_gen, book3.title, book3.page_number, book3.price);
    book3_det.general_details(&book3_gen);
    show_details(book3_gen);

    return 0;
}
