#                                                                      ООП-Практикум Домашно 6

Имплементирайте абстрактен клас Mob, с данни – name (string) health (double), dmg (double) и isAlive (bool). Нека класът има метод attack(<друг моб>), метод die(), който променя статуса на моба на мъртъв, както и метод getType, който ще връща типа на дадения моб под формата на стринг. Създайте класовете Hero, Enemy и Enemies, които наследяват Mob, със следните странични ефекти:

**Enemy** – има член данни: тип като типовете може да са small, average и big. Също Enemy, не може да атакува друго Enemy или пък Enemies. Когато Enemy атакува Hero, първо трябва да снижи бронята на героя до 0, след това го атакува, в случай, че героя е умрял, атаката се прекъсва. Също в зависимост от типа на Enemy му се променя данната dmg, small – същата си остава, НО директно маха от hp-то на героя, average умножава се по 1.5, big умножава се по 2. При атака се снижава health или armor (ако е останала такава) на героя на база данната dmg на Enemy. За getType да се връща “enemy”.

**Enemies** – представлява контейнер от Mob-ове, които са само Enemy. Не може да атакува други обекти от тип Enemies или Enemy. При атака всички мобове в тази групичка атакуват аргумента на метод attack, в случай че не е мъртъв. За getType да се връща “enemies”.

**Hero** – има данни: тип на атаката като те са два вида normal attack и splash attack, както и armor (int). Също един Hero не може да атакува друг Hero, а при атака ако типа на атаката му е splash attack и атакува Enemies ще нарани всяко Enemy от групата, ако няма, ще нарани първото живо, ако атакува Enemy типа на атака не от значение. Ако Enemy или Enemies са мъртви да се прекрати атаката. Един герой е мъртъв когато health стане 0. За getType да се връща “hero”.

#### Помислете за това как да осъществите, кой клас какво може да „атакува“ в метод attack. (може би с още едно наследяване или друго?)

Да се имплементира сериализация и десериализация както и да се напишат exception – и, където може.
