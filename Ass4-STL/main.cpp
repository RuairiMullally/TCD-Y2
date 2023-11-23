/* CE2 Assignment 4 Testing File
 * Authors: Sean McGoff, Darragh Elliott
 * To use, make this your main entry point for a compiled executable
 */
#include "Album.h"
#include "AlbumCollection.h"
#include <iostream>
#include <sstream>
#include <vector>

class testCase {
private:
	void (*tf)();   // Test Function (test1, test2, etc.)
	std::string eo; // Expected Output
public:
	// Constructor
	testCase(void (*test_func)(), std::string expected_output) :
			tf(test_func), eo(expected_output) {
	}
	;
	// Get Expected Output
	std::string getExpectedOutput() {
		return this->eo;
	}
	;
	// Stream Buffer Madness (NOT THREAD SAFE AT ALL)
	std::string captureOutput() {
		std::stringstream b;
		std::streambuf *old = std::cout.rdbuf(b.rdbuf());
		tf();
		std::string o = b.str();
		std::cout.rdbuf(old);
		return o;
	}
	// The Actual Test Function
	bool test() {
		return captureOutput() == this->eo;
	}
};
// test cases one two and three are the ones provided.
void test1() {
	Album album1("The Beatles", "Sgt Pepper's Lonely Hearts Club Band", 1967);
	Album album2("Jay-Z", "The Blueprint", 2001);
	std::cout << "album1 == album2 ? " << (album1 == album2) << std::endl;
	std::cout << "album1 < album2 ? " << (album1 < album2) << std::endl;
	std::cout << "album1 > album2 ? " << (album2 < album1) << std::endl;
}
void test2() {
	AlbumCollection db;
	db.InsertAlbum("The Beatles", "Sgt Pepper's Lonely Hearts Club Band", 1967);
	db.InsertAlbum("Jay-Z", "The Blueprint", 2001);
	db.InsertAlbum("The White Stripes", "Elephant", 2003);
	db.InsertAlbum("Dua Lipa", "Future Nostalgia", 2020);
	db.InsertAlbum("Taylor Swift", "Red (Taylor's Version)", 2021);
	db.InsertAlbum("The Beatles", "Yellow Submarine", 1969);
	db.InsertAlbum("The Plagiarist", "Future Nostalgia", 2021);
	db.Print();
	std::cout << "---" << std::endl;
	std::cout << "Delete all albums by artist 'The Beatles'." << std::endl;
	db.DeleteAlbumsByArtist("The Beatles");
	db.Print();
}
void test3() {
	AlbumCollection db;
	db.InsertAlbum("The Beatles", "Sgt Pepper's Lonely Hearts Club Band", 1967);
	db.InsertAlbum("Jay-Z", "The Blueprint", 2001);
	db.InsertAlbum("The White Stripes", "Elephant", 2003);
	db.InsertAlbum("Dua Lipa", "Future Nostalgia", 2020);
	db.InsertAlbum("Taylor Swift", "Red (Taylor's Version)", 2021);
	db.InsertAlbum("The Beatles", "Yellow Submarine", 1969);
	db.InsertAlbum("The Plagiarist", "Future Nostalgia", 2021);
	db.PrintByYear(2021);
}
void test4() {
	std::string artist = "Lemon Demon";
	std::string title = "Ultimate Showdown of Ultimate Destiny";
	int year = 2005;
	Album album(artist, title, year);
	std::cout << "Artist name correct: " << (album.GetArtist() == artist)
			<< std::endl;
	std::cout << "Song title correct: " << (album.GetTitle() == title)
			<< std::endl;
	std::cout << "Song year correct: " << (album.GetYear() == year)
			<< std::endl;
}
void test5() { //detailed comparison check
	Album album1("The White Stripes", "Elephant", 2003);
	Album album2("The White Stripes", "Elephant", 2004);
	Album album3("The White Stripes", "Elephant1", 2003);
	Album album4("The White Stripes1", "Elephant", 2003);
	std::cout << "album1<album2: " << (album1 < album2) << std::endl;
	std::cout << "album1<album3: " << (album1 < album3) << std::endl;
	std::cout << "album1<album4: " << (album1 < album4) << std::endl;

	std::cout << "album1>album2: " << (album2 < album1) << std::endl;
	std::cout << "album1>album3: " << (album3 < album1) << std::endl;
	std::cout << "album1>album4: " << (album4 < album1) << std::endl;

}
void test6() { // Add same album repeatedly, and collection length
	AlbumCollection db;
	db.InsertAlbum("Lemon Demon", "Ultimate Showdown of Ultimate Destiny",
			2005);
	db.InsertAlbum("Lemon Demon", "Ultimate Showdown of Ultimate Destiny",
			2005);
	db.InsertAlbum("Lemon Demon", "Ultimate Showdown of Ultimate Destiny",
			2005);
	std::cout << "Collection has " << db.GetNumberAlbums() << " Albums"
			<< std::endl;
	db.InsertAlbum("The Beatles", "Sgt Pepper's Lonely Hearts Club Band", 1967);
	db.InsertAlbum("Jay-Z", "The Blueprint", 2001);
	db.InsertAlbum("The White Stripes", "Elephant", 2003);
	db.InsertAlbum("Dua Lipa", "Future Nostalgia", 2020);
	std::cout << "Collection has " << db.GetNumberAlbums() << " Albums"
			<< std::endl;
	std::cout << "Deleting by title \"The Blueprint\"" << std::endl;
	db.DeleteAlbumByTitle("The Blueprint");
	std::cout << "Collection has " << db.GetNumberAlbums() << " Albums"
			<< std::endl;

}
void test7() { // contains and delete
	AlbumCollection db;
	db.InsertAlbum("The Beatles", "Sgt Pepper's Lonely Hearts Club Band", 1967);
	db.InsertAlbum("Jay-Z", "The Blueprint", 2001);
	db.InsertAlbum("The White Stripes", "Elephant", 2003);
	db.InsertAlbum("Copyright Infringement Man", "Elephant", 2004);
	db.InsertAlbum("Dua Lipa", "Future Nostalgia", 2020);
	db.InsertAlbum("Taylor Swift", "Red (Taylor's Version)", 2021);
	db.InsertAlbum("The Beatles", "Yellow Submarine", 1969);
	db.InsertAlbum("The Plagiarist", "Future Nostalgia", 2021);
	//Check if positive contains work
	std::cout << "Contains artist \"Jay-Z\": " << db.ContainsArtist("Jay-Z")
			<< std::endl;
	std::cout << "Contains title \"The Blueprint\": "
			<< db.ContainsTitle("The Blueprint") << std::endl;
	std::cout << "Contains year \"2001\": " << db.ContainsYear(2001)
			<< std::endl;

	// Check if delete by title removes song
	std::cout << "Deleting by title \"The Blueprint\"" << std::endl;
	db.DeleteAlbumByTitle("The Blueprint");
	// Check if negative contains work
	std::cout << "Contains artist \"Jay-Z\": " << db.ContainsArtist("Jay-Z")
			<< std::endl;
	std::cout << "Contains title \"The Blueprint\": "
			<< db.ContainsTitle("The Blueprint") << std::endl;
	std::cout << "Contains year \"2001\": " << db.ContainsYear(2001)
			<< std::endl;

	// Test delete by artist removes all songs by artist
	std::cout << "Contains artist \"The Beatles\": "
			<< db.ContainsArtist("The Beatles") << std::endl;
	std::cout << "Deleting by artist \"The Beatles\"" << std::endl;
	db.DeleteAlbumsByArtist("The Beatles");
	std::cout << "Contains artist \"The Beatles\": "
			<< db.ContainsArtist("The Beatles") << std::endl;
}
void test8() { // Delete by title deletes only one
	Album album1("The White Stripes", "Elephant", 2003);
	Album album2("Copyright Infringement Man", "Elephant", 2004);
	AlbumCollection db;
	db.InsertAlbum("The White Stripes", "Elephant", 2003);
	db.InsertAlbum("Copyright Infringement Man", "Elephant", 2004);
	// Checking if delete by title removes only first song
	std::cout << "Contains title \"Elephant\": " << db.ContainsTitle("Elephant")
			<< std::endl;
	std::cout << "Contains artist \"The White Stripes\": "
			<< db.ContainsArtist("The White Stripes") << std::endl;
	std::cout << "Contains artist \"Copyright Infringement Man\": "
			<< db.ContainsArtist("Copyright Infringement Man") << std::endl;
	std::cout << "Deleting by title \"Elephant\"" << std::endl;
	std::cout << "Which album is greater?" << std::endl;
	db.DeleteAlbumByTitle("Elephant");
	std::cout << "Contains title \"Elephant\": " << db.ContainsTitle("Elephant")
			<< std::endl;
	std::cout << "Contains artist \"The White Stripes\": "
			<< db.ContainsArtist("The White Stripes") << std::endl;
	std::cout << "Contains artist \"Copyright Infringement Man\": "
			<< db.ContainsArtist("Copyright Infringement Man") << std::endl;
}
void test9() { // Printing with filters
	AlbumCollection db;
	db.InsertAlbum("The Beatles", "Sgt Pepper's Lonely Hearts Club Band", 1967);
	db.InsertAlbum("Jay-Z", "The Blueprint", 2001);
	db.InsertAlbum("The White Stripes", "Elephant", 2003);
	db.InsertAlbum("Copyright Infringement Man", "Elephant", 2003);
	db.InsertAlbum("Dua Lipa", "Future Nostalgia", 2020);
	db.InsertAlbum("Taylor Swift", "Red (Taylor's Version)", 2021);
	db.InsertAlbum("The Beatles", "Yellow Submarine", 1969);
	db.InsertAlbum("The Plagiarist", "Future Nostalgia", 2021);
	db.Print();
	std::cout << std::endl;
	db.PrintByTitleSubstring("pha");
	std::cout << std::endl;
	db.PrintByTitleSubstring("Null");
	std::cout << std::endl;
	db.PrintByArtist("The Beatles");
	std::cout << std::endl;
	db.PrintByArtist("Elvis");
	std::cout << std::endl;
	db.PrintByYear(2003);
	std::cout << std::endl;
	db.PrintByYear(0);
}

int main() {
	vector<testCase> tests;
	tests.push_back(
			testCase { &test1, "album1 == album2 ? 0\n"s
					+ "album1 < album2 ? 0\n"s + "album1 > album2 ? 1\n"s });
	tests.push_back(
			testCase { &test2,
					"Dua Lipa, Future Nostalgia (2020)\n"s
							+ "Jay-Z, The Blueprint (2001)\n"s
							+ "Taylor Swift, Red (Taylor's Version) (2021)\n"s
							+ "The Beatles, Sgt Pepper's Lonely Hearts Club Band (1967)\n"s
							+ "The Beatles, Yellow Submarine (1969)\n"s
							+ "The Plagiarist, Future Nostalgia (2021)\n"s
							+ "The White Stripes, Elephant (2003)\n"s + "---\n"s
							+ "Delete all albums by artist 'The Beatles'.\n"s
							+ "Dua Lipa, Future Nostalgia (2020)\n"s
							+ "Jay-Z, The Blueprint (2001)\n"s
							+ "Taylor Swift, Red (Taylor's Version) (2021)\n"s
							+ "The Plagiarist, Future Nostalgia (2021)\n"s
							+ "The White Stripes, Elephant (2003)\n"s });
	tests.push_back(
			testCase { &test3, "Taylor Swift, Red (Taylor's Version) (2021)\n"s
					+ "The Plagiarist, Future Nostalgia (2021)\n"s });
	tests.push_back(
			testCase { &test4, "Artist name correct: 1\n"s
					+ "Song title correct: 1\n"s + "Song year correct: 1\n"s });
	tests.push_back(
			testCase { &test5, "album1<album2: 1\n"s + "album1<album3: 1\n"s
					+ "album1<album4: 1\n"s + "album1>album2: 0\n"s
					+ "album1>album3: 0\n"s + "album1>album4: 0\n"s });
	tests.push_back(
			testCase { &test6, "Collection has 1 Albums\n"s
					+ "Collection has 5 Albums\n"s
					+ "Deleting by title \"The Blueprint\"\n"s
					+ "Collection has 4 Albums\n"s });
	tests.push_back(
			testCase { &test7, "Contains artist \"Jay-Z\": 1\n"s
					+ "Contains title \"The Blueprint\": 1\n"s
					+ "Contains year \"2001\": 1\n"s
					+ "Deleting by title \"The Blueprint\"\n"s
					+ "Contains artist \"Jay-Z\": 0\n"s
					+ "Contains title \"The Blueprint\": 0\n"s
					+ "Contains year \"2001\": 0\n"s
					+ "Contains artist \"The Beatles\": 1\n"s
					+ "Deleting by artist \"The Beatles\"\n"s
					+ "Contains artist \"The Beatles\": 0\n"s });
	tests.push_back(
			testCase { &test8, "Contains title \"Elephant\": 1\n"s
					+ "Contains artist \"The White Stripes\": 1\n"s
					+ "Contains artist \"Copyright Infringement Man\": 1\n"s
					+ "Deleting by title \"Elephant\"\n"s
					+ "Which album is greater?\n"s
					+ "Contains title \"Elephant\": 1\n"s
					+ "Contains artist \"The White Stripes\": 1\n"s
					+ "Contains artist \"Copyright Infringement Man\": 0\n"s });
	tests.push_back(
			testCase { &test9,
					"Copyright Infringement Man, Elephant (2003)\n"s
							+ "Dua Lipa, Future Nostalgia (2020)\n"s
							+ "Jay-Z, The Blueprint (2001)\n"s
							+ "Taylor Swift, Red (Taylor's Version) (2021)\n"s
							+ "The Beatles, Sgt Pepper's Lonely Hearts Club Band (1967)\n"s
							+ "The Beatles, Yellow Submarine (1969)\n"s
							+ "The Plagiarist, Future Nostalgia (2021)\n"s
							+ "The White Stripes, Elephant (2003)\n"s + "\n"s
							+ "Copyright Infringement Man, Elephant (2003)\n"s
							+ "The White Stripes, Elephant (2003)\n"s + "\n"s
							+ "\n"s
							+ "The Beatles, Sgt Pepper's Lonely Hearts Club Band (1967)\n"s
							+ "The Beatles, Yellow Submarine (1969)\n"s + "\n"s
							+ "\n"s
							+ "Copyright Infringement Man, Elephant (2003)\n"s
							+ "The White Stripes, Elephant (2003)\n"s + "\n"s });

	bool didCasePass;
	for (unsigned long long int i = 0; i < tests.size(); ++i) {
		std::cout << "Test Case " << i + 1 << ":\n-------------\n";
		didCasePass = tests[i].test();
		std::cout << "Test Case " << i + 1 << " "
				<< (didCasePass ? "Passed!" : "Failed") << "\n";
		if (!didCasePass) {
			std::cout << "Expected Output:\n" << tests[i].getExpectedOutput()
					<< "\n";
			std::cout << "Student Output:\n" << tests[i].captureOutput()
					<< "\n";
		}
		std::cout << "\n\n";
	}
}
