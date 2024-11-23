#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book_info
{
protected:
    string bookname, author, publication;
    int bookID, no_of_copies;

public:
    void setData()
    {
        cout << "\nEnter the bookname of the book: ";
        cin >> bookname;
        cout << "\nEnter the bookname of author : ";
        cin >> author;
        cout << "\nEnter the publication : ";
        cin >> publication;
        cout << "\nEnter the No. of Copies : ";
        cin >> no_of_copies;
    }
    void getData()
    {
        cout << "\n=====Books Details====";
        cout << "\nID : " << bookID;
        cout << "\nThe bookname of book : " << bookname;
        cout << "\nThe bookname of author: " << author;
        cout << "\nThe publication : " << publication;
        cout << "\nThe No. of Copies: " << no_of_copies;
    }
    void writeFile()
    {
        ofstream write;
        write.open("Book_info.txt", ios::app);
        write << "\n"
              << bookID;
        write << "\n"
              << bookname;
        write << "\n"
              << author;
        write << "\n"
              << publication;
        write << "\n"
              << no_of_copies;
        write.close();
    }
    void readFile()
    {
        ifstream read;
        read.open("Book_info.txt");
        while (!read.eof())
        {
            read >> bookID;
            read >> bookname;
            read >> author;
            read >> publication;
            read >> no_of_copies;
        }
        read.close();
    }
    int searchData(int key)
    {
        ifstream read;
        read.open("Book_info.txt");
        while (!read.eof())
        {
            read >> bookID;
            read >> bookname;
            read >> author;
            read >> publication;
            read >> no_of_copies;
            if (key == bookID)
            {
                read.close();
                return bookID;
            }
        }
        return 0;
    }
    void deleteData()
    {
        int deleteID;
        cout << "\nEnter the id of book you want to Delete : ";
        cin >> deleteID;
        int key = searchData(deleteID);
        cout << "\nYou want to delete record (y/n) : ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream read;
            read.open("Book_info.txt");
            while (!read.eof())
            {
                read >> bookID;
                read >> bookname;
                read >> author;
                read >> publication;
                read >> no_of_copies;
                if (bookID != key)
                {
                    tempfile << "\n"
                             << bookID;
                    tempfile << "\n"
                             << bookname;
                    tempfile << "\n"
                             << author;
                    tempfile << "\n"
                             << publication;
                    tempfile << "\n"
                             << no_of_copies;
                }
            }
            remove("Book_info.txt");
            rename("temp.txt", "Book_info.txt");
            tempfile.close();
        }
    }
    void updateData()
    {
        int updateID;
        cout << "\nEnter the id of book you want to Update : ";
        cin >> updateID;
        int key = searchData(updateID);
        char choice;
        cout << "\n\tYou want to update record (y/n) : ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            Book_info tempbook;
            tempbook.setData();
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream read;
            read.open("Book_info.txt");
            while (!read.eof())
            {
                read >> bookID;
                read >> bookname;
                read >> author;
                read >> publication;
                read >> no_of_copies;
                if (bookID != key)
                {
                    tempfile << "\n"
                             << bookID;
                    tempfile << "\n"
                             << bookname;
                    tempfile << "\n"
                             << author;
                    tempfile << "\n"
                             << publication;
                    tempfile << "\n"
                             << no_of_copies;
                }
                else
                {
                    tempfile << "\n"
                             << bookID;
                    tempfile << "\n"
                             << tempbook.bookname;
                    tempfile << "\n"
                             << tempbook.author;
                    tempfile << "\n"
                             << tempbook.publication;
                    tempfile << "\n"
                             << tempbook.no_of_copies;
                }
            }
            remove("Book_info.txt");
            rename("temp.txt", "Book_info.txt");
            cout << "\n\tData updated successfuly";
        }
    }
    void displayData()
    {
        ifstream read;
        read.open("Book_info.txt");
        while (!read.eof())
        {
            read >> bookID;
            read >> bookname;
            read >> author;
            read >> publication;
            read >> no_of_copies;
            getData();
        }
        read.close();
    }
    void addData()
    {
        bookID++;
        setData();
        writeFile();
    }
};
Book_info book;

class Librarian_info
{
protected:
    string name, qualification;
    int librarianID, experience;

public:
    void setData()
    {
        cout << "\nEnter the name of the Librarian: ";
        cin >> name;
        cout << "\nEnter his/her Qualification in Years : ";
        cin >> qualification;
        cout << "\nEnter the Experience : ";
        cin >> experience;
    }
    void getData()
    {
        cout << "\n=====Librarian Details====";
        cout << "\nID : " << librarianID;
        cout << "\nThe name of Librarian : " << name;
        cout << "\nQualification of Librarian : " << qualification;
        cout << "\nThe Experience in Years : " << experience;
    }
    void writeFile()
    {
        ofstream write;
        write.open("Librarian_info.txt", ios::app);
        write << "\n"
              << librarianID;
        write << "\n"
              << name;
        write << "\n"
              << qualification;
        write << "\n"
              << experience;
        write.close();
    }
    void readFile()
    {
        ifstream read;
        read.open("Librarian_info.txt");
        while (!read.eof())
        {
            read >> librarianID;
            read >> name;
            read >> qualification;
            read >> experience;
        }
        read.close();
    }
    int searchData(int key)
    {
        ifstream read;
        read.open("Librarian_info.txt");
        while (!read.eof())
        {
            read >> librarianID;
            read >> name;
            read >> qualification;
            read >> experience;
            if (key == librarianID)
            {
                read.close();
                return librarianID;
            }
        }
        return 0;
    }
    void deleteData()
    {
        int deleteID;
        cout << "\nEnter the id of book you want to Delete : ";
        cin >> deleteID;
        int key = searchData(deleteID);
        cout << "\nYou want to delete record (y/n) : ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream read;
            read.open("Librarian_info.txt");
            while (!read.eof())
            {
                read >> librarianID;
                read >> name;
                read >> qualification;
                read >> experience;
                if (librarianID != key)
                {
                    tempfile << "\n"
                             << librarianID;
                    tempfile << "\n"
                             << name;
                    tempfile << "\n"
                             << qualification;
                    tempfile << "\n"
                             << experience;
                }
            }
            remove("Librarian_info.txt");
            rename("temp.txt", "Librarian_info.txt");
            tempfile.close();
        }
    }
    void updateData()
    {
        int updateID;
        cout << "\nEnter the id of book you want to Update : ";
        cin >> updateID;
        int key = searchData(updateID);
        char choice;
        cout << "\n\tYou want to update record (y/n) : ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            Librarian_info tempbook;
            tempbook.setData();
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream read;
            read.open("Librarian_info.txt");
            while (!read.eof())
            {
                read >> librarianID;
                read >> name;
                read >> qualification;
                read >> experience;
                if (librarianID != key)
                {
                    tempfile << "\n"
                             << librarianID;
                    tempfile << "\n"
                             << name;
                    tempfile << "\n"
                             << qualification;
                    tempfile << "\n"
                             << experience;
                }
                else
                {
                    tempfile << "\n"
                             << librarianID;
                    tempfile << "\n"
                             << tempbook.name;
                    tempfile << "\n"
                             << tempbook.qualification;
                    tempfile << "\n"
                             << tempbook.experience;
                }
            }
            remove("Librarian_info.txt");
            rename("temp.txt", "Librarian_info.txt");
            cout << "\n\tData updated successfuly";
        }
    }
    void displayData()
    {
        ifstream read;
        read.open("Librarian_info.txt");
        while (!read.eof())
        {
            read >> librarianID;
            read >> name;
            read >> qualification;
            read >> experience;
            getData();
        }
        read.close();
    }
    void addData()
    {
        librarianID++;
        setData();
        writeFile();
    }
};
Librarian_info librarian;

class Student_info
{
protected:
    string studentname, department, classroom, division;
    int studentID;

public:
    void setData()
    {
        cout << "\nEnter the studentname of the book: ";
        cin >> studentname;
        cout << "\nEnter the studentname of author : ";
        cin >> department;
        cout << "\nEnter the publication : ";
        cin >> classroom;
        cout << "\nEnter the No. of Copies : ";
        cin >> division;
    }
    void getData()
    {
        cout << "\n=====Student Details====";
        cout << "\nID : " << studentID;
        cout << "\nThe studentname of book : " << studentname;
        cout << "\nThe studentname of author: " << department;
        cout << "\nThe publication : " << classroom;
        cout << "\nThe No. of Copies: " << division;
    }
    void writeFile()
    {
        ofstream write;
        write.open("Student_info.txt", ios::app);
        write << "\n"
              << studentID;
        write << "\n"
              << studentname;
        write << "\n"
              << department;
        write << "\n"
              << classroom;
        write << "\n"
              << division;
        write.close();
    }
    void readFile()
    {
        ifstream read;
        read.open("Student_info.txt");
        while (!read.eof())
        {
            read >> studentID;
            read >> studentname;
            read >> department;
            read >> classroom;
            read >> division;
        }
        read.close();
    }
    int searchData(int key)
    {
        ifstream read;
        read.open("Student_info.txt");
        while (!read.eof())
        {
            read >> studentID;
            read >> studentname;
            read >> department;
            read >> classroom;
            read >> division;
            if (key == studentID)
            {
                read.close();
                return studentID;
            }
        }
        return 0;
    }
    void deleteData()
    {
        int deleteID;
        cout << "\nEnter the id of book you want to Delete : ";
        cin >> deleteID;
        int key = searchData(deleteID);
        cout << "\nYou want to delete record (y/n) : ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream read;
            read.open("Student_info.txt");
            while (!read.eof())
            {
                read >> studentID;
                read >> studentname;
                read >> department;
                read >> classroom;
                read >> division;
                if (studentID != key)
                {
                    tempfile << "\n"
                             << studentID;
                    tempfile << "\n"
                             << studentname;
                    tempfile << "\n"
                             << department;
                    tempfile << "\n"
                             << classroom;
                    tempfile << "\n"
                             << division;
                }
            }
            remove("Student_info.txt");
            rename("temp.txt", "Student_info.txt");
            tempfile.close();
        }
    }
    void updateData()
    {
        int updateID;
        cout << "\nEnter the id of book you want to Update : ";
        cin >> updateID;
        int key = searchData(updateID);
        char choice;
        cout << "\n\tYou want to update record (y/n) : ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            Student_info tempbook;
            tempbook.setData();
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream read;
            read.open("Student_info.txt");
            while (!read.eof())
            {
                read >> studentID;
                read >> studentname;
                read >> department;
                read >> classroom;
                read >> division;
                if (studentID != key)
                {
                    tempfile << "\n"
                             << studentID;
                    tempfile << "\n"
                             << studentname;
                    tempfile << "\n"
                             << department;
                    tempfile << "\n"
                             << classroom;
                    tempfile << "\n"
                             << division;
                }
                else
                {
                    tempfile << "\n"
                             << studentID;
                    tempfile << "\n"
                             << tempbook.studentname;
                    tempfile << "\n"
                             << tempbook.department;
                    tempfile << "\n"
                             << tempbook.classroom;
                    tempfile << "\n"
                             << tempbook.division;
                }
            }
            remove("Student_info.txt");
            rename("temp.txt", "Student_info.txt");
            cout << "\n\tData updated successfuly";
        }
    }
    void displayData()
    {
        ifstream read;
        read.open("Student_info.txt");
        while (!read.eof())
        {
            read >> studentID;
            read >> studentname;
            read >> department;
            read >> classroom;
            read >> division;
            getData();
        }
        read.close();
    }
    void addData()
    {
        studentID++;
        setData();
        writeFile();
    }
};
Student_info student;

class BookIssue_info : Student_info, Book_info
{
    string date;
    int issueID;

public:
    void setData()
    {
        cout << "\nEnter the Name of the student: ";
        cin >> studentname;
        cout << "\nEnter the Name of the book Issued : ";
        cin >> bookname;
        cout << "\nEnter the Date of Issue(DD/MM/YYYY) : ";
        cin >> date;
    }
    void getData()
    {
        cout << "\n=====Issued Book Details====";
        cout << "\nIssue ID : " << issueID;
        // cout << "\nStudent ID : " << studentID;
        cout << "\nStudent Name : " << studentname;
        // cout << "\nBook ID : " << bookID;
        cout << "\nBook name: " << bookname;
        cout << "\nDate of Issue: " << date;
    }
    void writeFile()
    {
        ofstream write;
        write.open("BookIssue_info.txt", ios::app);
        write << "\n"
              << issueID;
        write << "\n"
              << studentname;
        write << "\n"
              << bookname;
        write << "\n"
              << date;
        write.close();
    }
    void readFile()
    {
        ifstream read;
        read.open("BookIssue_info.txt");
        while (!read.eof())
        {
            read >> issueID;
            read >> studentname;
            read >> bookname;
            read >> date;
        }
        read.close();
    }
    int searchData(int key)
    {
        ifstream read;
        read.open("BookIssue_info.txt");
        while (!read.eof())
        {
            read >> issueID;
            read >> studentname;
            read >> bookname;
            read >> date;
            if (key == issueID)
            {
                read.close();
                return issueID;
            }
        }
        return 0;
    }
    void deleteData()
    {
        int deleteID;
        cout << "\nEnter the id of comp you want to Delete : ";
        cin >> deleteID;
        int key = searchData(deleteID);
        cout << "\nYou want to delete record (y/n) : ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream read;
            read.open("BookIssue_info.txt");
            while (!read.eof())
            {
                read >> issueID;
                read >> studentname;
                read >> bookname;
                read >> date;
                if (issueID != key)
                {
                    tempfile << "\n"
                             << issueID;
                    tempfile << "\n"
                             << studentname;
                    tempfile << "\n"
                             << bookname;
                    tempfile << "\n"
                             << date;
                }
            }
            remove("BookIssue_info.txt");
            rename("temp.txt", "BookIssue_info.txt");
            tempfile.close();
        }
    }
    void updateData()
    {
        int updateID;
        cout << "\nEnter the id of comp you want to Update : ";
        cin >> updateID;
        int key = searchData(updateID);
        char choice;
        cout << "\n\tYou want to update record (y/n) : ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            BookIssue_info tempComp;
            tempComp.setData();
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream read;
            read.open("BookIssue_info.txt");
            while (!read.eof())
            {
                read >> issueID;
                read >> studentname;
                read >> bookname;
                read >> date;
                if (issueID != key)
                {
                    tempfile << "\n"
                             << issueID;
                    tempfile << "\n"
                             << studentname;
                    tempfile << "\n"
                             << bookname;
                    tempfile << "\n"
                             << date;
                }
                else
                {
                    tempfile << "\n"
                             << issueID;
                    tempfile << "\n"
                             << tempComp.studentname;
                    tempfile << "\n"
                             << tempComp.bookname;
                    tempfile << "\n"
                             << tempComp.date;
                }
            }
            remove("BookIssue_info.txt");
            rename("temp.txt", "BookIssue_info.txt");
            cout << "\n\tData updated successfuly";
        }
    }
    void displayData()
    {
        ifstream read;
        read.open("BookIssue_info.txt");
        while (!read.eof())
        {
            read >> issueID;
            read >> studentname;
            read >> bookname;
            read >> date;
            getData();
        }
        read.close();
    }
    void change_book_d()
    {
        int key = bookID;
        ifstream read;
        read.open("Book_info.txt");
        ofstream write;
        write.open("temp.txt");
        while (!read.eof())
        {
            read >> bookID;
            read >> bookname;
            read >> author;
            read >> publication;
            read >> no_of_copies;

            if (key != bookID)
            {
                write << "\n"
                      << bookID;
                write << "\n"
                      << bookname;
                write << "\n"
                      << author;
                write << "\n"
                      << publication;
                write << "\n"
                      << no_of_copies;
            }
            else{
                write << "\n"
                      << bookID;
                write << "\n"
                      << bookname;
                write << "\n"
                      << author;
                write << "\n"
                      << publication;
                write << "\n"
                      << no_of_copies-1;
            }
        }
        write.close();
        read.close();
        remove("Book_info.txt");
        rename("temp.txt" , "Book_info.txt");
    }
    void addData()
    {
        issueID++;
        setData();
        string key = bookname;
        ifstream read;
        read.open("Book_info.txt");
        while (key != bookname)
        {
            read >> bookID;
            read >> bookname;
            read >> author;
            read >> publication;
            read >> no_of_copies;
        }
        read.close();
        if (no_of_copies != 0)
        {
        writeFile();
        change_book_d();  
        }
        else {
            cout<<"\n\nSorry! The book is not available.";
        }
    }
    
};
BookIssue_info bookissue;

int main()
{
    int main_choice = 1, bookChoice, librarianChoice, studentChoice, issueChoice;
    while (main_choice != 0)
    {
        cout << "\n==========Main Menu==========";
        cout << "\n1. Books Details";
        cout << "\n2. Librarian Details";
        cout << "\n3. Student Details";
        cout << "\n4. Issued Book Details";
        cout << "\nPress 0 to exit";
        cout << "\n==============================";
        cout << "\nEnter Choice : ";
        cin >> main_choice;
        switch (main_choice)
        {
        case 0:
            break;
        case 1:
            while (bookChoice != 0)
            {
                ofstream write;
                write.open("Book_info.txt", ios::app);
                write.close();
                book.readFile();
                cout << "\n=====Books Details=====";
                cout << "\n1. Display Data";
                cout << "\n2. Add Data";
                cout << "\n3. Delete Data";
                cout << "\n4. Update Data";
                cout << "\nPress 0 to Go Back";
                cout << "\n======================================";
                cout << "\nEnter Choice : ";
                cin >> bookChoice;
                switch (bookChoice)
                {
                case 0:
                    break;
                case 1:
                    book.displayData();
                    cout << "\n\n\n\n\n";
                    break;
                case 2:
                    book.addData();
                    cout << "\n\n\n\n\n";
                    break;
                case 3:
                    book.deleteData();
                    cout << "\n\n\n\n\n";
                    break;
                case 4:
                    book.updateData();
                    break;

                default:
                    cout << "\ninvalid Choice";
                    cout << "\n\n\n\n\n";
                    break;
                }
            }
            bookChoice = 1;
            break;
        case 2:
            while (librarianChoice != 0)
            {
                ofstream write;
                write.open("Librarian_info.txt", ios::app);
                write.close();
                librarian.readFile();
                cout << "\n=====Librarian Details=====";
                cout << "\n1. Display Data";
                cout << "\n2. Add Data";
                cout << "\n3. Delete Data";
                cout << "\n4. Update Data";
                cout << "\nPress 0 to Go Back";
                cout << "\n======================================";
                cout << "\nEnter Choice : ";
                cin >> librarianChoice;
                switch (librarianChoice)
                {
                case 0:
                    break;
                case 1:
                    librarian.displayData();
                    cout << "\n\n\n\n\n";
                    break;
                case 2:
                    librarian.addData();
                    cout << "\n\n\n\n\n";
                    break;
                case 3:
                    librarian.deleteData();
                    cout << "\n\n\n\n\n";
                    break;
                case 4:
                    librarian.updateData();
                    break;

                default:
                    cout << "\ninvalid Choice";
                    cout << "\n\n\n\n\n";
                    break;
                }
            }
            librarianChoice = 1;
            break;
        case 3:
            while (studentChoice != 0)
            {
                ofstream write;
                write.open("Student_info.txt", ios::app);
                write.close();
                student.readFile();
                cout << "\n=====Student Details=====";
                cout << "\n1. Display Data";
                cout << "\n2. Add Data";
                cout << "\n3. Delete Data";
                cout << "\n4. Update Data";
                cout << "\nPress 0 to Go Back";
                cout << "\n======================================";
                cout << "\nEnter Choice : ";
                cin >> studentChoice;
                switch (studentChoice)
                {
                case 0:
                    break;
                case 1:
                    student.displayData();
                    cout << "\n\n\n\n\n";
                    break;
                case 2:
                    student.addData();
                    cout << "\n\n\n\n\n";
                    break;
                case 3:
                    student.deleteData();
                    cout << "\n\n\n\n\n";
                    break;
                case 4:
                    student.updateData();
                    break;

                default:
                    cout << "\ninvalid Choice";
                    cout << "\n\n\n\n\n";
                    break;
                }
            }
            studentChoice = 1;
            break;

        case 4:
            while (issueChoice != 0)
            {
                ofstream write;
                write.open("BookIssue_info.txt", ios::app);
                write.close();
                bookissue.readFile();
                cout << "\n=====Book Issue Details=====";
                cout << "\n1. Display Data";
                cout << "\n2. Add Data";
                cout << "\n3. Delete Data";
                cout << "\n4. Update Data";
                cout << "\nPress 0 to Go Back";
                cout << "\n======================================";
                cout << "\nEnter Choice : ";
                cin >> issueChoice;
                switch (issueChoice)
                {
                case 0:
                    break;
                case 1:
                    bookissue.displayData();
                    cout << "\n\n\n\n\n";
                    break;
                case 2:
                    bookissue.addData();
                    cout << "\n\n\n\n\n";
                    break;
                case 3:
                    bookissue.deleteData();
                    cout << "\n\n\n\n\n";
                    break;
                case 4:
                    bookissue.updateData();
                    break;

                default:
                    cout << "\ninvalid Choice";
                    cout << "\n\n\n\n\n";
                    break;
                }
            }
            issueChoice = 1;
            break;

        default:
            cout << "\ninvalid Choice";
            cout << "\n\n\n\n\n";
            break;
        }
    }
    return 0;
}