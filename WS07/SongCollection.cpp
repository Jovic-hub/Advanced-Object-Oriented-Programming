/**********************************************************
 * Name: Joao Victor Fernandes dos Santos
 * Student ID:155858194
 * Seneca email: jvfernandes-dos-sant@myseneca.ca
 * Section: OOP345 - NFF
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "SongCollection.h"
#include "SongCollection.h"

namespace sdds {
	SongCollection::SongCollection(string name) {
		std::ifstream file(name);
		if (file) {
			while (file) {
				string file_line, title, artist, album, year, lenght, price;
				Song song;

				getline(file, file_line, '\n');

				title = file_line.substr(0, 25);
				title.erase(title.find_last_not_of(' ') + 1);
				title.erase(0, title.find_first_not_of(' '));
				file_line.erase(0, 25);
				song.m_title = title;

				artist = file_line.substr(0, 25);
				artist.erase(artist.find_last_not_of(' ') + 1);
				artist.erase(0, artist.find_first_not_of(' '));
				file_line.erase(0, 25);
				song.m_artist = artist;

				album = file_line.substr(0, 25);
				album.erase(album.find_last_not_of(' ') + 1);
				album.erase(0, album.find_first_not_of(' '));
				file_line.erase(0, 25);
				song.m_album = album;

				year = file_line.substr(0, 5);
				year.erase(year.find_last_not_of(' ') + 1);
				year.erase(0, year.find_first_not_of(' '));
				file_line.erase(0, 5);
				song.releaseYear = year;

				lenght = file_line.substr(0, 5);
				lenght.erase(lenght.find_last_not_of(' ') + 1);
				lenght.erase(0, lenght.find_first_not_of(' '));
				file_line.erase(0, 5);


				price = file_line.substr(0, 5);
				price.erase(price.find_last_not_of(' ') + 1);
				price.erase(0, price.find_first_not_of(' '));
				file_line.erase(0, 5);

				stringstream len(lenght);
				len >> song.lengthOfTheSong;

				stringstream pri(price);
				pri >> song.m_price;
				
				m_song.push_back(song);
			}
		}
		else {
			throw "Invalid file name";
		}
		m_song.pop_back();
	}

	void SongCollection::display(std::ostream& out) const {
		for_each(m_song.begin(), m_song.end(), [&](const Song& song) {
			out << song << endl;
		});
		out << "----------------------------------------------------------------------------------------" << endl;
		size_t a = 0;
		for_each(m_song.begin(), m_song.end(), [&](const Song& song) {
			a += song.lengthOfTheSong;
		});

		int m_hour = (a / 60) / 60;
		int m_min = (a / 60) % 60;
		int m_sec = a % 60;
		out << "|                                                        Total Listening Time: " << m_hour << ":" << m_min << ":" << m_sec << " |" << endl;

	}
	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
			out << "| " << setw(20) << left << theSong.m_title << " | ";
			out.setf(ios::left);
			out << setw(15) << theSong.m_artist << " | ";
			out << setw(20) << theSong.m_album << " | ";
			out << right;
			out << setw(6) << theSong.releaseYear << " | ";
			int m_min = theSong.lengthOfTheSong / 60;
			int m_sec = theSong.lengthOfTheSong % 60;

			out << m_min << ":";
			if (m_sec < 10) {
				out << '0' << m_sec << " | ";
			}
			else {
				out << m_sec << " | ";
			}
			out << theSong.m_price << " |";
			out.unsetf(ios::left);

		return out;
	}

	void SongCollection::sort(string name) {
		if (name == "title") {
			std::sort(m_song.begin(), m_song.end(), [](Song A, Song B) {
				return A.m_title < B.m_title;
			});
		}
		else if (name == "album") {
			std::sort(m_song.begin(), m_song.end(), [](Song A, Song B) {
				return A.m_album < B.m_album;
			});
		}
		else if (name == "length") {
			std::sort(m_song.begin(), m_song.end(), [](Song A, Song B) {
				return A.lengthOfTheSong < B.lengthOfTheSong;
			});
		}
	}
	void SongCollection::cleanAlbum() {
		for_each(m_song.begin(), m_song.end(), [](Song& song) {
			if (song.m_album == "[None]") {
				song.m_album = "";
			}
		});
	}
	bool SongCollection::inCollection(string name) const {
		auto in = find_if(m_song.begin(), m_song.end(), [&name](const Song& song) {
			return song.m_artist == name;
		});
		return in != m_song.end();
	}
	std::list<Song> SongCollection::getSongsForArtist(string name) const {
		list<Song>m_list(std::count_if(m_song.begin(), m_song.end(), [&name](const Song& song) {
			return song.m_artist == name;
			}));

		copy_if(m_song.begin(), m_song.end(), m_list.begin(),[&name](const Song& ssong) {
			return ssong.m_artist == name;
		});
		return m_list;
	}
}
