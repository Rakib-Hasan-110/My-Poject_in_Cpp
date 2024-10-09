#include <iostream>
#include <string>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book() : id(0), title(""), author(""), isIssued(false) {}

    Book(int id, string title, string author) : id(id), title(title), author(author), isIssued(false) {}

    void display() {
        cout << "ID: " << id << "\nTitle: " << title << "\nAuthor: " << author << "\nIssued: " << (isIssued ? "Yes" : "No") << endl;
    }
};
class Library {
private:
    Book books[100]; // Array of books, max 100 books
    int bookCount;

public:
    Library() : bookCount(0) {}

    void addBook(int id, string title, string author) {
        if (bookCount < 100) {
            books[bookCount] = Book(id, title, author);
            bookCount++;
        } else {
            cout << "Library is full, cannot add more books." << endl;
        }
    }

    void issueBook(int id) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == id && !books[i].isIssued) {
                books[i].isIssued = true;
                cout << "Book issued successfully." << endl;
                return;
            }
        }
        cout << "Book not found or already issued." << endl;
    }

    void returnBook(int id) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == id && books[i].isIssued) {
                books[i].isIssued = false;
                cout << "Book returned successfully." << endl;
                return;
            }
        }
        cout << "Book not found or not issued." << endl;
    }

    void displayBooks() {
        if (bookCount == 0) {
            cout << "No books in the library." << endl;
        } else {
            for (int i = 0; i < bookCount; i++) {
                books[i].display();
                cout << "-----------------" << endl;
            }
        }
    }
};
int main() {
    Library library;

    // Adding some books to the library
    library.addBook(1, "The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook(2, "To Kill a Mockingbird", "Harper Lee");
    library.addBook(3, "1984", "George Orwell");

    // Display all books
    cout << "All books in the library:" << endl;
    library.displayBooks();

    // Issue a book
    cout << "\nIssuing book with ID 1:" << endl;
    library.issueBook(1);

    // Display all books
    cout << "\nAll books in the library after issuing a book:" << endl;
    library.displayBooks();

    // Return a book
    cout << "\nReturning book with ID 1:" << endl;
    library.returnBook(1);

    // Display all books
    cout << "\nAll books in the library after returning a book:" << endl;
    library.displayBooks();

    return 0;
}
