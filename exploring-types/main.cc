struct Date {
  int day, month, year;
};

class Table {
  Table(const Table&);
  Table& operator=(const Table&);
};

class Club {
  string name;
  Table members;
  Table officers;
  Date founded;

  Club(const string& n, Date fd);
};

int main() {

}
