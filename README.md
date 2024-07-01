# Catan Game

## תיאור הפרויקט
פרויקט זה מדמה משחק קטאן (Catan) עם שחקנים, לוח משחק, קלפי פיתוח ועוד. הפרויקט נכתב בשפת C++ ומשתמש ב-Google Test לבדיקות יחידה.

## חוקי המשחק
משחק הקטאן מיועד למספר שחקנים ומתבצע על גבי לוח משחק המחולק להקסגונים, כל אחד מייצג משאב אחר. השחקנים בונים יישובים, דרכים וערים, ומנסים לאסוף משאבים ולהגיע ל10 נקודות ניצחון .

### מהלך המשחק
1. כל שחקן מתחיל עם שני יישובים ושני דרכים.
2. כל סיבוב, שחקן זורק שתי קוביות והמספר שהתקבל קובע אילו משאבים יחולקו לשחקנים.
3. שחקנים יכולים לבנות יישובים, דרכים וערים באמצעות המשאבים שברשותם.
4. ניתן לרכוש קלפי פיתוח המקנים נקודות נוספות או יכולות מיוחדות.
5. המשחק מסתיים כאשר שחקן מגיע ל10 נקודות ניצחון או יותר בתורו.

## היררכיית המחלקות

### מחלקת Board
מחלקה זו מנהלת את לוח המשחק.
- `void init_board()`: מאתחלת את לוח המשחק עם משאבים ותכונות אחרות.
- `Vertex& get_vertex(int id)`: מחזירה את ה-Vertex לפי מזהה.
- `Edge& get_edge(int id)`: מחזירה את ה-Edge לפי מזהה.
- `Hexagon& get_hexagon(int id)`: מחזירה את ההקסגון לפי מזהה.
- `std::vector<Vertex>& get_vertexs()`: מחזירה וקטור של כל ה-Vertices.
- `std::vector<Edge>& get_edges()`: מחזירה וקטור של כל ה-Edges.
- `std::vector<Hexagon>& get_hexagons()`: מחזירה וקטור של כל ההקסגונים.

### מחלקת Catan
מחלקה זו מנהלת את המשחק עצמו.
- `Catan(Player& p1, Player& p2, Player& p3)`: קונסטרוקטור שמקבל שלושה שחקנים.
- `void ChooseStartingPlayer()`: בוחרת את השחקן שמתחיל את המשחק.
- `void round(int res)`: מבצעת סיבוב במשחק בהתבסס על תוצאה של זריקת קוביות.
- `void bring_player_resorese(int vertex, Player& player)`: מביאה משאבים לשחקן בהתבסס על ה-Vertex הנתון.
- `void printWinner()`: מדפיסה את שם השחקן המנצח אם יש כזה.

### מחלקת Player
מחלקה זו מייצגת שחקן במשחק.
- `Player(string name)`: קונסטרוקטור שמקבל שם של שחקן.
- `int get_points() const`: מחזירה את מספר הנקודות של השחקן.
- `string get_name() const`: מחזירה את שם השחקן.
- `int get_age() const`: מחזירה את גיל השחקן.
- `void increase_points(int inc)`: מגדילה את הנקודות של השחקן במספר הנתון.
- `void use_card(Catan& catan, Board& board)`: משתמשת בכרטיס פיתוח.
- `void placeCity(int placeNum, Board& board)`: ממקמת עיר בלוח המשחק.
- `void placeSettelemnt(int placesNum, Board& board)`: ממקמת יישוב בלוח המשחק.
- `void placeRoad(int roadNum, Board& board)`: ממקמת כביש בלוח המשחק.
- `void trade(Player& other, const string& my_card, const string& other_card, int my_amount, int other_amount)`: מבצעת סחר בין השחקנים.
- `void buyDevelopmentCard(Deck& deck)`: רוכשת כרטיס פיתוח.
- `int rollTwoDice(Board& board)`: זורקת שני קוביות ומחזירה את התוצאה.
- `void endTurn()`: מסיימת את התור של השחקן הנוכחי.
- `void reduce_half_resources()`: מצמצמת חצי מהמשאבים של השחקן אם יש לו יותר משבעה.

### מחלקת Hexagon
מחלקה זו מייצגת הקסגון על לוח המשחק.
- `Hexagon(int id, const std::string& resource, int number)`: קונסטרוקטור שמקבל מזהה, סוג משאב ומספר הקסגון.
- `int get_id() const`: מחזירה את מזהה ההקסגון.
- `std::string get_resource() const`: מחזירה את סוג המשאב של ההקסגון.
- `int get_number() const`: מחזירה את מספר ההקסגון.
- `void add_vertex(Vertex* vertex)`: מוסיפה נקודת Vertex להקסגון.
- `std::vector<Vertex*>& get_vertex()`: מחזירה את וקטור ה-Vertices של ההקסגון.

### מחלקת Vertex
מחלקה זו מייצגת נקודה על לוח המשחק.
- `Vertex(int id)`: קונסטרוקטור שמקבל מזהה.
- `int get_id() const`: מחזירה את מזהה ה-Vertex.
- `std::string get_available() const`: מחזירה את המצב הנוכחי של ה-Vertex (פנוי או תפוס).
- `int get_num_player() const`: מחזירה את מספר השחקן שה-Vertex שייך לו.
- `void set_available(const std::string& status, int player_num)`: מגדירה את ה-Vertex כפנוי או תפוס ואת מספר השחקן.
- `std::vector<int>& get_edge_nei()`: מחזירה את וקטור השכנים של ה-Edge.

### מחלקת Edge
מחלקה זו מייצגת דרך על לוח המשחק.
- `Edge(int id)`: קונסטרוקטור שמקבל מזהה.
- `int get_id() const`: מחזירה את מזהה ה-Edge.
- `int get_num_player() const`: מחזירה את מספר השחקן שה-Edge שייך לו.
- `void set_available(const std::string& status, int player_num)`: מגדירה את ה-Edge כפנוי או תפוס ואת מספר השחקן.
- `std::vector<Edge*>& get_neibours()`: מחזירה את וקטור השכנים של ה-Edge.
- `std::vector<Vertex*>& get_ver_nei()`: מחזירה את וקטור ה-Vertices השכנים של ה-Edge.

### מחלקת Development Card
מחלקה זו מנהלת את קלפי הפיתוח.
- `void KnightCard::use(Player& player, std::vector<Player*>& players, Board& board)`: משתמשת בכרטיס אביר.
- `void VictoryPointCard::use(Player& player, std::vector<Player*>& players, Board& board)`: משתמשת בכרטיס נקודת ניצחון.
- `void MonopolyCard::use(Player& player, std::vector<Player*>& players, Board& board)`: משתמשת בכרטיס מונופול.
- `void RoadBuildingCard::use(Player& player, std::vector<Player*>& players, Board& board)`: משתמשת בכרטיס בניית כביש.
- `void YearOfPlentyCard::use(Player& player, std::vector<Player*>& players, Board& board)`: משתמשת בכרטיס שנת שפע.
- `Deck::Deck()`: קונסטרוקטור שמוסיף קלפים לחבילה ומערבב אותם.
- `DevelopCard* Deck::drawCard()`: שולף קלף מהחבילה.

## ספריות בשימוש
- **Google Test**: לבדיקות יחידה.
- **CMake**: כלי בנייה ליצירת קבצי Makefile.
- **Valgrind**:כלי לבדיקת זליגת זיכרון.
