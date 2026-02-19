#include<iostream>
using namespace std;

class Manager {
private:
	string managername;
public:
	Manager(string name = "") {
		managername = name;

	}
	string getname() const { return managername; }
	friend ostream& operator<<(ostream& out, const Manager& m) {
		out << "Manager Name: " << m.managername;
		return out;
	}
	~Manager() {
		cout << "Manager destroyed: " << managername << endl;
	}
};
class Movie {
private:
	string moviename;
	int time;
	Manager* manager; //association
public:
	Movie(string name = "", int t = 0, Manager* m = nullptr) {
		moviename = name;
		time = t;
		manager = m;
	}
	friend ostream& operator<<(ostream& out, const Movie& mv) {
		out << "Movie Name: " << mv.moviename << ", Time: " << mv.time;
		if (mv.manager) {
			out << ", " << *(mv.manager);
		}
		return out;
	}
	Manager* getmanager() const { return manager; }
	~Movie() {
		cout << "Movie destroyed: " << moviename << endl;
	}

};
class Theater {
private:
	string theatername;
	Movie* movies[10]; //composition
	int movienum;
public:
	Theater(string name = "") {
		theatername = name;
		movienum = 0;
		for (int i = 0; i < 10; i++) {
			movies[i] = nullptr;
		}
	}
	void addMovie(Movie* m) {
		if (movienum < 10) {
			movies[movienum] = m;
			movienum++;
		}
	}

	void showMovies() {
		cout << "--- Movies Running in " << theatername << " ---\n";
		for (int i = 0; i < movienum; i++) {
			cout << *movies[i] << "\n\n";
		}
	}

	~Theater() {
		cout << "Theater destroyed: " << theatername << endl;
	}
};
int main() {
	string name1;
	cout << "Enter name of Manager 1: ";
	cin >> name1;

	Manager* m1 = new Manager(name1);
	string name2;
	cout << "Enter name of Manager 2: ";
	cin >> name2;
	Manager* m2 = new Manager(name2);
	Movie* mv1 = new Movie("Inception", 148, m1);
	Movie* mv2 = new Movie("The Dark Knight", 152, m2);
	Movie* mv3 = new Movie("Interstellar", 169);
	string theatername;
	cout << "enter name of theater:";
	cin >> theatername;
	Theater t1(theatername);
	t1.addMovie(mv1);
	t1.addMovie(mv2);
	t1.addMovie(mv3);
	t1.showMovies();
	// deletion
	delete mv1;
	delete mv2;
	delete mv3;
	delete m1;
	delete m2;
	return 0;
}

