## Общие сведения

### 1. Цель проекта
   Разработать функционирующую модель "Скибиди туалета" для увеселения людей.
### 2. Команда исполнителей
   Козодой, Михайлов, Щетинин, Тахватулин

## Технические требования

### 1. Требования к функциональным характеристикам
 - Возможность передвигаться по поверхности
 - Воспроизведение звуковых материалов, связанных со скибиди туалетами
 - Возможность качать головой в разные стороны
### 2. Требования к надежности
 - *отсутствуют*
### 3. Условия эксплуатации
 - Не использовать модель в разрушительных для нее условиях (под водой, вблизи огня)
 - Не подвергать модель разрушительному воздействию гравитации (не ронять)
### 4. Требования к составу и параметрам технических средств
 - Питание изделия должно осуществляться от 2 батареек типа AA (2,4 - 3 вольта).
 - Микроконтроллер должен обладать достаточной производительностью и обладать периферией для загрузки аудио с flash памяти, подачи сигнала на динамик, управлением моторчиками.
 - Flash память должна вмещать трек не менее 4 секунд с битрейтом 16 и частотой дискретизации 44100 Гц.
### 5. Требования к информационной и программной совместимости
 - Программная часть изделия должна быть разработана с помощью языков программирования ASM/C.

## Требования к документации

Должны быть написаны:
 - Инструкция по эксплуатации изделия
 - Документация к программной части (или читаемый код)
 - Схема аппаратной части

## Технико-экономические показатели

 - [Flash-память для 20 (двадцати) секундного трека](https://www.chipdip.ru/product/w25q32jvssiq) - 54 рубля
 - [Микроконтроллер с поддержкой SPI, UART и ШИМ](https://www.chipdip.ru/product0/8016772393) - 47 рублей
 - [Динамик](https://www.chipdip.ru/product0/8031024898) - 18 рублей
 - [Сервопривод](https://www.ozon.ru/product/servoprivod-servomotor-sg-90-360-gradusov-9g-arduino-1574661606/?asb2=wDt9T_jkdWd4z83JwZONb0wokMBvGMnvHYeOZoPjcqMjCJL0lDIqwhGUU4wTg79n&avtc=1&avte=2&avts=1727030776&keywords=%D1%81%D0%B5%D1%80%D0%B2%D0%BE%D0%BF%D1%80%D0%B8%D0%B2%D0%BE%D0%B4) - 170 рублей
 - [Моторчик](https://www.chipdip.ru/product0/8008724455) - 120 рублей

## Cтадии и этапы разработки

1. Определение функциональных требований к изделию. &check;
2. Определение методов достижения поставленных требований. &check;
  * Генерация и отбраковка идей. &check;
  * Выбор подходящих комплектующих. &check;
3. Разработка электротехнической схемы изделия. &check;
4. Разработка 3d моделей изделия и компонентов (шестерёнки, etc.)
5. Разработка программной части.
6. Сборка изделия и прошивка.
7. Тестирование.
8. Устранение неполадок, обнаруженных при тестировании.

## Порядок контроля и приемки

Испытания отсутствуют. Единственный критерий выполнения ТЗ - выполнение всех изложенных требований

## Ссылки на источники

1. ГОСТ 19.201-78 Техническое задание. Требования к содержанию и оформлению
2. [CH32V203F6P6 Datasheets](https://www.wch-ic.com/downloads/CH32V203DS0_PDF.html).
3. [W25Q32JV Datasheet](https://static.chipdip.ru/lib/306/DOC029306111.pdf).


## Архитектура

## Аппаратная часть (схемотехника)
![alt text](image.png)

## Программная часть
![alt text](image-1.png)