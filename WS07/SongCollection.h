/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#ifndef Song_Collection_H
#define Song_Collection_H
#include<iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
#include <fstream>
#include <list>
#include <vector>
#include <functional>
using namespace std;
namespace sdds {

	struct Song {
			string m_artist;
			string m_title;
			string m_album;
			double m_price;
			string releaseYear;
			size_t lengthOfTheSong;
	};

	class SongCollection {
		vector<Song> m_song;
	public:
		vector<Song> size_song;
		SongCollection(string name);
		void display(std::ostream& out) const;
		void sort(string name);
		void cleanAlbum();
		bool inCollection(string name) const;
		std::list<Song> getSongsForArtist(string name) const;
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif