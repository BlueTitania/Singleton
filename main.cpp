#include <iostream>

using namespace std;

class Singleton
{
  public:
    static Singleton& GetInstance(){
        // getInstance() используется статический экземпляр нужного класса
        //тандарт языка программирования C++ гарантирует автоматическое уничтожение
        //статических объектов при завершении программы. Деструктор не нужен
        static Singleton instance;//отложенная инциализация, т.е инициализация при первом вызове getInstance()
        return instance;
    }

   void print(char* text){
       cout<<text<<endl;
   }

  private:
    //не доступные поля, предотвращение создание экземпляров класса за пределами его реализации
    Singleton() {}
    Singleton(Singleton const&);
    Singleton& operator= (Singleton const&);
};

int main()
{
    Singleton& s1 = Singleton::GetInstance();
    s1.print("Hello, I am singletone");
    cout<<&s1;
    //Singleton& s2 = Singleton::GetInstance();//ошибка, т к поле приватное
    //s2=s1;

    return 0;
}

