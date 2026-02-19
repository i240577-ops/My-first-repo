//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class LibraryBook {
//private:
//    char* title;
//    int bookID;
//    static int totalBooks;
//
//    static char* allocateAndCopy(const char* src) {
//        if (!src) {
//            char* temp = new char[1];
//            temp[0] = '\0';
//            return temp;
//        }
//        int len = strlen(src);
//        char* temp = new char[len + 1];
//        for (int i = 0; i <= len; i++)
//            temp[i] = src[i];
//        return temp;
//    }
//
//public:
//    LibraryBook(const char* t, int id) : bookID(id) {
//        title = allocateAndCopy(t);
//        totalBooks++;
//    }
//
//    LibraryBook(const LibraryBook& other) {
//        bookID = other.bookID;
//        title = allocateAndCopy(other.title);
//        totalBooks++;
//    }
//
//    ~LibraryBook() {
//        delete[] title;
//        totalBooks--;
//    }
//
//    void display() const {
//        cout << "Book ID: " << bookID << endl;
//        cout << "Title: " << title << endl;
//    }
//
//    void setTitle(const char* newTitle) {
//        delete[] title;
//        title = allocateAndCopy(newTitle);
//    }
//
//    static int getTotalBooks() {
//        return totalBooks;
//    }
//};
//
//int LibraryBook::totalBooks = 0;
//
//int main() {
//    char titleInput[100];
//    int id;
//
//    cout << "Enter book title: ";
//    cin.getline(titleInput, 100);
//
//    cout << "Enter book ID: ";
//    cin >> id;
//
//    LibraryBook* originalBook = new LibraryBook(titleInput, id);
//
//    cout << "Original book details:" << endl;
//    originalBook->display();
//
//    LibraryBook copiedBook(*originalBook);
//
//    cout << "Copied book details =" << endl;
//    copiedBook.display();
//
//    cin.ignore();
//    cout << "Enter a new title for the original book: ";
//    cin.getline(titleInput, 100);
//    originalBook->setTitle(titleInput);
//
//    cout << "Original Book:" << endl;
//    originalBook->display();
//
//    cout << "Copied Book =" << endl;
//    copiedBook.display();
//
//    cout << "Total books currently in system: "
//        << LibraryBook::getTotalBooks() << endl;
//
//    delete originalBook;
//
//    cout << "Total books currently in system: "
//        << LibraryBook::getTotalBooks() << endl;
//
//    return 0;
//}
#include <iostream>
using namespace std;

int main() {
    unsigned int tmp;
    unsigned char SYS;
    int P;

    if (!(cin >> tmp)) return 0;
    SYS = (unsigned char)(tmp & 0xFF);
    unsigned char LOG = 0;
    cin >> P;

    // Animatronics stored as *masks* (exactly one bit set)
    unsigned char A1 = (1u << 0);
    unsigned char A2 = (1u << 0);
    unsigned char A3 = (1u << 0);
    unsigned char A4 = (1u << 0);

    // temporary vars reused
    int night = 0;
    while (night < 5) {
        int evt;
        if (!(cin >> evt)) evt = -1;

        // Save start-of-night masks (for determining "prev room" if they move into office)
        unsigned char startA1 = A1, startA2 = A2, startA3 = A3, startA4 = A4;
        bool moved1 = false, moved2 = false, moved3 = false, moved4 = false;
        int a, t, load;
        char X;

        switch (evt) {
        case 1: // Move: 1 a t
            if (!(cin >> a >> t)) { cout << "InvalidTarget" << endl; break; }
            if (!(a >= 1 && a <= 4) || !(t >= 0 && t <= 7)) { cout << "InvalidTarget" << endl; break; }

            // find current index (0..7) for the requested animatronic
            int curIdx = 0;
            if (a == 1) {
                for (int i = 0; i < 8; i++) if (startA1 & (1u << i)) { curIdx = i; break; }
            }
            else if (a == 2) {
                for (int i = 0; i < 8; i++) if (startA2 & (1u << i)) { curIdx = i; break; }
            }
            else if (a == 3) {
                for (int i = 0; i < 8; i++) if (startA3 & (1u << i)) { curIdx = i; break; }
            }
            else {
                for (int i = 0; i < 8; i++) if (startA4 & (1u << i)) { curIdx = i; break; }
            }

            // validate adjacency according to graph
            int ok = 0;
            if (curIdx == 0) { if (t == 1 || t == 2) ok = 1; }           // Stage <-> HallL, HallR
            if (curIdx == 1) { if (t == 0 || t == 7 || t == 4) ok = 1; }    // HallL <-> Stage, Office, Labs
            if (curIdx == 2) { if (t == 0 || t == 7 || t == 5) ok = 1; }    // HallR <-> Stage, Office, Library
            if (curIdx == 3) { if (t == 7 || t == 6) ok = 1; }            // Vent <-> Office, Courtyard
            if (curIdx == 4) { if (t == 1) ok = 1; }                   // Labs <-> HallL
            if (curIdx == 5) { if (t == 2) ok = 1; }                   // Library <-> HallR
            if (curIdx == 6) { if (t == 3) ok = 1; }                   // Courtyard <-> Vent
            if (curIdx == 7) { if (t == 1 || t == 2 || t == 3) ok = 1; }    // Office <-> HallL, HallR, Vent

            if (!ok) {
                cout << "InvalidMove" << endl;
            }
            else {
                unsigned char mask = (unsigned char)(1u << t);
                if (a == 1) { A1 = mask; moved1 = true; }
                if (a == 2) { A2 = mask; moved2 = true; }
                if (a == 3) { A3 = mask; moved3 = true; }
                if (a == 4) { A4 = mask; moved4 = true; }
            }
            break;

        case 2: // Jam: 2 X
            if (!(cin >> X)) { cout << "InvalidCode" << endl; break; }
            if (X != 'L' && X != 'R' && X != 'V') { cout << "InvalidCode" << endl; break; }
            if (X == 'L') {
                unsigned char before = SYS;
                SYS |= (1u << 1); // LeftDoor closed
                if ((before & (1u << 1)) == 0) LOG |= (1u << 1);
                cout << "DoorSealed" << endl;
            }
            else if (X == 'R') {
                unsigned char before = SYS;
                SYS |= (1u << 2); // RightDoor closed
                if ((before & (1u << 2)) == 0) LOG |= (1u << 2);
                cout << "DoorSealed" << endl;
            }
            else { // V
                unsigned char before = SYS;
                SYS |= (1u << 3); // VentGate closed
                if ((before & (1u << 3)) == 0) LOG |= (1u << 3);
                cout << "VentSealed" << endl;
            }
            break;

        case 3: // Brownout: 3 load
            if (!(cin >> load)) { cout << "InvalidLoad" << endl; break; }
            if (load < 0 || load > 200) { cout << "InvalidLoad" << endl; break; }
            if (load > 120) {
                if ((SYS & (1u << 6)) == 0) { // Generator == 0
                    cout << "Outage" << endl;
                    if (SYS & (1u << 4)) { SYS &= ~(1u << 4); LOG |= (1u << 4); } // StageLights -> 0
                    if (SYS & (1u << 5)) { SYS &= ~(1u << 5); LOG |= (1u << 5); } // VentFans -> 0
                }
                else {
                    cout << "Stable" << endl;
                }
            }
            break;

        case 4: // Override: 4 X
            if (!(cin >> X)) { cout << "InvalidCode" << endl; break; }
            if (X != 'C' && X != 'L' && X != 'F' && X != 'G' && X != 'A') { cout << "InvalidCode" << endl; break; }
            if (X == 'C') { SYS ^= (1u << 0); LOG |= (1u << 0); }         // Cameras
            else if (X == 'L') { SYS ^= (1u << 4); LOG |= (1u << 4); }    // StageLights
            else if (X == 'F') { SYS ^= (1u << 5); LOG |= (1u << 5); }    // VentFans
            else if (X == 'G') { SYS ^= (1u << 6); LOG |= (1u << 6); }    // Generator
            else { // Alarm A
                unsigned char newSYS = SYS ^ (1u << 7);
                // If trying to turn Alarm on AND any of LeftDoor, RightDoor, VentGate is 0 -> CallSecurity
                if ((newSYS & (1u << 7)) && ((SYS & (1u << 1)) == 0 || (SYS & (1u << 2)) == 0 || (SYS & (1u << 3)) == 0)) {
                    cout << "CallSecurity" << endl;
                    // clear Alarm to 0 and set LOG bit7
                    SYS &= ~(1u << 7);
                    LOG |= (1u << 7);
                }
                else {
                    SYS = newSYS;
                    LOG |= (1u << 7);
                }
            }
            break;

        default:
            cout << "CorruptEvent" << endl;
            break;
        } // end switch

        // --- Safety rules (in order) ---
        // 1) Energy saver
        if ((SYS & (1u << 4)) && !(SYS & (1u << 6))) {
            cout << "DimMode" << endl;
            if (SYS & (1u << 4)) { SYS &= ~(1u << 4); LOG |= (1u << 4); }
        }
        // 2) Printer trap prevention
        if (!(SYS & (1u << 0)) && (SYS & (1u << 1)) && (SYS & (1u << 2))) {
            cout << "BlindLock" << endl;
            if (SYS & (1u << 2)) { SYS &= ~(1u << 2); LOG |= (1u << 2); }
        }
        // 3) Vent evacuation
        if ((SYS & (1u << 7)) && (SYS & (1u << 5))) {
            cout << "Evacuate" << endl;
            if (SYS & (1u << 5)) { SYS &= ~(1u << 5); LOG |= (1u << 5); }
        }

        // --- Power drain ---
        int k = 0;
        for (int b = 0; b < 8; b++) if (SYS & (1u << b)) k++;
        P -= 2 * k;
        if (P < 0) P = 0;
        if (P == 0) {
            cout << "LimpMode" << endl;
            if (SYS & (1u << 0)) { SYS &= ~(1u << 0); LOG |= (1u << 0); } // Cameras
            if (SYS & (1u << 4)) { SYS &= ~(1u << 4); LOG |= (1u << 4); } // StageLights
            if (SYS & (1u << 5)) { SYS &= ~(1u << 5); LOG |= (1u << 5); } // VentFans
        }

        // --- Office safety check ---
        // For each animatronic: decide its entry and check barrier if currently in Office (bit7)
        // We must use the room *before* it moved this night if it moved via evt=1; otherwise treat as Vent.
        // For each animatronic we compare masks.

        // A1
        if (A1 & (1u << 7)) {
            int entryIdx = 3; // default Vent
            if (moved1) {
                // find prev index from startA1
                for (int i = 0; i < 8; i++) if (startA1 & (1u << i)) { entryIdx = i; break; }
            }
            bool blocked = false;
            if (entryIdx == 1 && (SYS & (1u << 1))) blocked = true; // HallL -> LeftDoor
            if (entryIdx == 2 && (SYS & (1u << 2))) blocked = true; // HallR -> RightDoor
            if (entryIdx == 3 && (SYS & (1u << 3))) blocked = true; // Vent -> VentGate
            if (!blocked) {
                cout << "Caught" << endl;
                A1 = (1u << 0); // push to Stage
                LOG |= (1u << 0);
            }
        }
        // A2
        if (A2 & (1u << 7)) {
            int entryIdx = 3;
            if (moved2) { for (int i = 0; i < 8; i++) if (startA2 & (1u << i)) { entryIdx = i; break; } }
            bool blocked = false;
            if (entryIdx == 1 && (SYS & (1u << 1))) blocked = true;
            if (entryIdx == 2 && (SYS & (1u << 2))) blocked = true;
            if (entryIdx == 3 && (SYS & (1u << 3))) blocked = true;
            if (!blocked) {
                cout << "Caught" << endl;
                A2 = (1u << 0);
                LOG |= (1u << 0);
            }
        }
        // A3
        if (A3 & (1u << 7)) {
            int entryIdx = 3;
            if (moved3) { for (int i = 0; i < 8; i++) if (startA3 & (1u << i)) { entryIdx = i; break; } }
            bool blocked = false;
            if (entryIdx == 1 && (SYS & (1u << 1))) blocked = true;
            if (entryIdx == 2 && (SYS & (1u << 2))) blocked = true;
            if (entryIdx == 3 && (SYS & (1u << 3))) blocked = true;
            if (!blocked) {
                cout << "Caught" << endl;
                A3 = (1u << 0);
                LOG |= (1u << 0);
            }
        }
        // A4
        if (A4 & (1u << 7)) {
            int entryIdx = 3;
            if (moved4) { for (int i = 0; i < 8; i++) if (startA4 & (1u << i)) { entryIdx = i; break; } }
            bool blocked = false;
            if (entryIdx == 1 && (SYS & (1u << 1))) blocked = true;
            if (entryIdx == 2 && (SYS & (1u << 2))) blocked = true;
            if (entryIdx == 3 && (SYS & (1u << 3))) blocked = true;
            if (!blocked) {
                cout << "Caught" << endl;
                A4 = (1u << 0);
                LOG |= (1u << 0);
            }
        }

        night++;
    } // end 5-night loop

    // Closing report
    cout << "SYS=";
    for (int i = 7; i >= 0; i--) cout << ((SYS & (1u << i)) ? '1' : '0');
    cout << endl;

    cout << "LOG=";
    for (int i = 7; i >= 0; i--) cout << ((LOG & (1u << i)) ? '1' : '0');
    cout << endl;

    int pop = 0;
    for (int i = 0; i < 8; i++) if (LOG & (1u << i)) pop++;

    int S = 50 + pop;
    if (SYS & (1u << 6)) S += 10;
    if (!(SYS & (1u << 0))) {
        S -= 15;
        if (SYS & (1u << 1)) S -= 5;
        if (SYS & (1u << 2)) S -= 5;
    }
    cout << "Score=" << S << endl;

    return 0;
}
