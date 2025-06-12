//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "LibrarySystem.h"
#include "Book.h"
#include "Thesis.h"
#include "DigitalResources.h"
#include "Article.h"
#include "MyDate.h"
 #include "EventManager.h"
 #include "FileManager.h"
 #include "IdGenerator.h"
 #include "Loan.h"
 #include "Notification.h"
 #include "Reservation.h"
 #include "Resource.h"
 #include "SearchEngine.h"
 #include "User.h"
 #include<string>
LibrarySystem Library;
EventManager eventManager;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{

   StringGrid1->Cells[0][0] = "ID";
	StringGrid1->Cells[1][0] = "Title";
	StringGrid1->Cells[2][0] = "Author";
	StringGrid1->Cells[3][0] = "Year";
   StringGrid1->Cells[4][0] = "Available";
   Library.loadData();     // Load data on startup
	refreshGrid();
    Memo1->Lines->Clear();


}
//---------------------------------------------------------------------------


void __fastcall TForm3::Button1Click(TObject *Sender)
{
 String name = InputBox("Add New User", "Enter user name:", "");

	if (!name.IsEmpty()) {
		std::string userId = IdGenerator::generate("U");                    // ✅ correct function call
		std::string userName = AnsiString(name).c_str();                   // ✅ convert from VCL String

		User newUser(userId, userName);                                    // ✅ correct constructor
		Library.addUser(newUser);

		ShowMessage("User added!\nID: " + String(userId.c_str()) +         // ✅ convert back to VCL String
			"\nName: " + name);
	}
	else {
		ShowMessage("User name cannot be empty.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
	String type = InputBox("Resource Type", "Enter type (Book, Thesis, Digital, Article):", "");
	String id = InputBox("Resource ID", "Enter ID:", "");
	String title = InputBox("Title", "Enter Title:", "");
	String author = InputBox("Author", "Enter Author:", "");
	String yearStr = InputBox("Year", "Enter Publication Year:", "");

	if (type.IsEmpty() || id.IsEmpty() || title.IsEmpty() || author.IsEmpty() || yearStr.IsEmpty()) {
		ShowMessage("All fields are required.");
		return;
	}

	int year = yearStr.ToInt();
	std::string rType = AnsiString(type).LowerCase().c_str();
	std::string rId = AnsiString(id).c_str();
	std::string rTitle = AnsiString(title).c_str();
	std::string rAuthor = AnsiString(author).c_str();

	// Create and add resource
	if (rType == "book") {
		Library.addResource(new Book(rId, rTitle, rAuthor, year));
	} else if (rType == "thesis") {
		Library.addResource(new Thesis(rId, rTitle, rAuthor, year));
	} else if (rType == "digital") {
		Library.addResource(new DigitalResource(rId, rTitle, rAuthor, year));
	} else if (rType == "article") {
		Library.addResource(new Article(rId, rTitle, rAuthor, year));
	} else {
		ShowMessage("Invalid resource type.");
		return;
	}

	ShowMessage("Resource added successfully.");
	refreshGrid();  // Optional: update grid
}
//---------------------------------------------------------------------------
    void __fastcall TForm3::refreshGrid()
{
	const std::vector<Resource*>& resources = Library.getAllResources();
	StringGrid1->RowCount = resources.size() + 1;

	for (int i = 0; i < resources.size(); ++i) {
		Resource* r = resources[i];
		StringGrid1->Cells[0][i + 1] = r->getId().c_str();
		StringGrid1->Cells[1][i + 1] = r->getTitle().c_str();
		StringGrid1->Cells[2][i + 1] = r->getAuthor().c_str();
		StringGrid1->Cells[3][i + 1] = IntToStr(r->getPublicationYear());
		StringGrid1->Cells[4][i + 1] = r->getAvailability() ? "Yes" : "No";
	}
}

void __fastcall TForm3::Button3Click(TObject *Sender)
{
String userId = InputBox("Borrow Resource", "Enter User ID:", "");
	String resourceId = InputBox("Borrow Resource", "Enter Resource ID:", "");

	if (userId.IsEmpty() || resourceId.IsEmpty()) {
		ShowMessage("Both fields are required.");
		return;
	}

	Library.borrowResource(AnsiString(userId).c_str(), AnsiString(resourceId).c_str());

	ShowMessage("Borrow request processed.");
	refreshGrid();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button4Click(TObject *Sender)
{
	String userId = InputBox("Return Resource", "Enter User ID:", "");
	String resourceId = InputBox("Return Resource", "Enter Resource ID:", "");

	if (userId.IsEmpty() || resourceId.IsEmpty()) {
		ShowMessage("Both fields are required.");
		return;
	}

	Library.returnResource(AnsiString(userId).c_str(), AnsiString(resourceId).c_str());

	ShowMessage("Return processed.");
	refreshGrid();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button5Click(TObject *Sender)
{
String keyword = SearchBox1->Text.Trim();  // ✅ Use your TSearchBox here

	if (keyword.IsEmpty()) {
		refreshGrid();  // Show all if no search term
		return;
	}

	const std::vector<Resource*>& allResources = Library.getAllResources();
	std::vector<Resource*> filtered;

	std::string key = AnsiString(keyword).LowerCase().c_str();

	for (auto* r : allResources) {
		std::string id     = r->getId();
		std::string title  = r->getTitle();
		std::string author = r->getAuthor();

		// Convert to lowercase to compare
		std::transform(id.begin(), id.end(), id.begin(), ::tolower);
		std::transform(title.begin(), title.end(), title.begin(), ::tolower);
		std::transform(author.begin(), author.end(), author.begin(), ::tolower);

		if (id.find(key) != std::string::npos ||
			title.find(key) != std::string::npos ||
			author.find(key) != std::string::npos) {
			filtered.push_back(r);
		}
	}

	// Show filtered results in grid
	StringGrid1->RowCount = filtered.size() + 1;

	for (int i = 0; i < filtered.size(); ++i) {
		Resource* r = filtered[i];
		StringGrid1->Cells[0][i + 1] = String(r->getId().c_str());
		StringGrid1->Cells[1][i + 1] = String(r->getTitle().c_str());
		StringGrid1->Cells[2][i + 1] = String(r->getAuthor().c_str());
		StringGrid1->Cells[3][i + 1] = IntToStr(r->getPublicationYear());
		StringGrid1->Cells[4][i + 1] = r->getAvailability() ? "Yes" : "No";
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button6Click(TObject *Sender)
{
SearchBox1->Text = "";
	refreshGrid();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button7Click(TObject *Sender)
{
    Library.saveData();

	ShowMessage("Data saved.");


}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button8Click(TObject *Sender)
{
MyDate today = MyDate::getToday();  // ✅ today’s date

	const std::vector<Loan>& loans = Library.getLoans();
	const std::vector<Resource*>& resources = Library.getAllResources();

	std::vector<Resource*> overdueResources;

	for (const Loan& loan : loans) {
		if (loan.getDueDate().isBefore(today)) {  // ✅ check overdue
			for (Resource* r : resources) {
				if (r->getId() == loan.getResourceId()) {
					overdueResources.push_back(r);
					break;
				}
			}
		}
	}

	StringGrid1->RowCount = overdueResources.size() + 1;

	for (int i = 0; i < overdueResources.size(); ++i) {
		Resource* r = overdueResources[i];
		StringGrid1->Cells[0][i + 1] = String(r->getId().c_str());
		StringGrid1->Cells[1][i + 1] = String(r->getTitle().c_str());
		StringGrid1->Cells[2][i + 1] = String(r->getAuthor().c_str());
		StringGrid1->Cells[3][i + 1] = IntToStr(r->getPublicationYear());
		StringGrid1->Cells[4][i + 1] = "Overdue";
	}

	if (overdueResources.empty()) {
		ShowMessage("No overdue resources.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button9Click(TObject *Sender)
{
    String title = InputBox("New Event", "Enter event title:", "");
	String date = InputBox("New Event", "Enter event date (e.g., 15/06/2025):", "");
	String desc = InputBox("New Event", "Enter event description:", "");

	if (title.IsEmpty() || date.IsEmpty()) {
		ShowMessage("Title and date are required.");
		return;
	}

	// 🔁 Convert VCL String to std::string safely
	std::string t = AnsiString(title).c_str();
	std::string d = AnsiString(date).c_str();
	std::string ds = AnsiString(desc).c_str();

	// ✅ Now the constructor matches
	Event e(t, d, ds);
	eventManager.addEvent(e);
	eventManager.saveEvents();

	ShowMessage("Event saved.");
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Button10Click(TObject *Sender)
{
eventManager.loadEvents();
	Memo1->Lines->Clear();

	const auto& events = eventManager.getAllEvents();
	for (const auto& e : events) {
		Memo1->Lines->Add( String(e.getDate().c_str()));
		Memo1->Lines->Add( String(e.getTitle().c_str()));
		Memo1->Lines->Add(  String(e.getDescription().c_str()));
		Memo1->Lines->Add("-----------------------------");
	}

	if (events.empty()) {
		Memo1->Lines->Add("No events available.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button11Click(TObject *Sender)
{
Close();

}
//---------------------------------------------------------------------------

