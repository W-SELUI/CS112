//Assignment 1 
//William Selui -  s11244878
//Sebastian Afeaki - s11206285

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX_INPUT = 100; // Maximum number of books the system can handle

// struct to hold the books information
struct Books{
	int Book_ID;
	string Book_Title;
	int Copies_Available;
};

// Function to return availability status of a book
string book_Status(int copies)
{
	if(copies > 0)
	{
		return "Available";
	}
	
	else
	{
		return "Out of Stock";
	}
}

// Prints details of all books in the system
void print_Books_Details(Books books[],int size)
{
	for(int i=0; i<size; i++)
	{
		cout << "ID  :  " << left << setw(5) << books[i].Book_ID;
		cout << "\tBook Title  : "  << left << setw(40) << books[i].Book_Title;
		cout << "\tCopies_Available  :  " << left << setw(5) << books[i].Copies_Available;
		cout << "\tBook Status  :  " << book_Status(books[i].Copies_Available) << endl;
	}
}

//Calculates and prints the total number of copies across all books
void print_Sum_of_copies (Books books[], int size)
{
	int sum = 0;
	
	for (int i=0; i<size; i++)
	{
		sum += books[i].Copies_Available;
	}
	
	cout << "Total number of books in stock:  " << sum << endl;
}

// Finds and prints the book with the highest number of copies available
void print_Book_with_highest_copies_available (Books books[], int size)
{
	int max = 0; // index of the book with the most copies
	
	for (int i=0; i<size; i++)
	{
		if (books[i].Copies_Available > books[max].Copies_Available)
		{
			max = i;	
		}	
	}	
	
	cout << "Book with the highest number of copies : " << endl;
	cout << "ID: " << books[max].Book_ID << "\t Book Title: " << books[max].Book_Title << "\t Copies Available: " << books[max].Copies_Available << endl;
	
}

// Calculates and prints the percentage of books that are out of stock
void print_percentage_books_out_of_stock ( Books books[], int size)
{

	int out_of_stock_count = 0;
	
	for (int i=0; i<size; i++)
	{
		
		if (books[i].Copies_Available == 0)
		{
			out_of_stock_count++;	
		}	
	}	
	
	double percentage = (out_of_stock_count * 100.0) / size;
	
	cout << "Percentage of books that are currently out of stock:  " << percentage <<"% " << endl;
}

// Allow user to update the number of copies for a specific book
// Updates are written back to the "books.txt" file
void update_functionality (Books books[], int size)
{
	int bookID;
	
	cout << "Enter the book ID of the book you want to update:  " ;
	cin >> bookID;
		
	bool found = false;
		
	for (int i=0; i<size; i++)
	{
		if(bookID == books[i].Book_ID)
		{

			int updatecopies;
				
			cout << "Whats the new update copies of the book you just entered:  ";
			cin >> updatecopies;
						
			// Input validation: must be a non-negative integer			
			while (cin.fail() || updatecopies < 0)
			{
				cin.clear();
				cin.ignore(1000,'\n');
				cout << "Invalid number. Enter 0 or more:  ";
				cin >> updatecopies;
			}
			
		
		
			books[i].Copies_Available = updatecopies;
			cout << "Book ID: " << bookID << " updated succesfully." << endl;
			found = true;
			break;
		}
	}
		
	if (!found)
	{
		cout << "Book ID not found." << endl;
	}
		
	else
	{
		//Rewrite entire file with updates book list
		ofstream out_file;
			
		out_file.open("books.txt");
			
		for (int i=0; i<size; i++)
		{
			out_file << books[i].Book_ID << " " << books[i].Book_Title << " " << books[i].Copies_Available << endl;
		}
			
		out_file.close();
	}	
}
	
int main(){
	
	ifstream infile;
	
	infile.open("books.txt"); // Open book data file
	
	Books books[MAX_INPUT];
	
	int count = 0;
	
	// Loads books from file until end of file
	while (infile >> books[count].Book_ID )
	{
		infile.ignore(); // ignore whitespace before title
		getline(infile, books[count].Book_Title, ',');
		infile >> books[count].Copies_Available;
		count++;
	}
	
	int answer = 0;
	
	cout << "Welcome to the Library Management System" << endl;
	
	//Menu loop
	while (answer != 6)
	{

		cout << endl;
	
		cout << "_________________________________________________________________" << endl;
		cout << "|   |                                                           |" << endl; 
		cout << "| 1 | Print books details.                                      |" << endl;
		cout << "| 2 | Print total number of books in stock.                     |" << endl;
		cout << "| 3 | Print book with the highest number of copies available.   |" << endl;
		cout << "| 4 | Print percentage of books that are currently out of stock.|" << endl;
		cout << "| 5 | Update the number of copies                               |" << endl;
		cout << "| 6 | Exit                                                      |" << endl;
		cout << "|___|___________________________________________________________|" << endl;
		
		cout << "Choose your option.";
		cin >> answer;
		
		cout << endl;
		
		// Input validation for menu choice
		while (cin.fail() || answer < 1 || answer > 6)
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "Invalid choice. Please enter a number from 1-6:  ";
			cin >> answer;
		}
		
		// Menu options
		if (answer == 1)
		{
			print_Books_Details(books,count);
			cout << endl;
		}
		
		else if (answer == 2)
		{
			print_Sum_of_copies(books,count);
			cout << endl;
		}
		
		else if (answer == 3)
		{
			print_Book_with_highest_copies_available(books,count);
			cout << endl;
		}
		
		else if (answer == 4)
		{
			print_percentage_books_out_of_stock(books,count);
			cout << endl;
		}
		
		else if (answer == 5)
		{ 
			update_functionality(books,count);
			cout << endl;
		}
		
		else if (answer == 6)
		{
			return 0;	
		}
		
	}
	
	cout << endl;
	
	
	return 0;
}


