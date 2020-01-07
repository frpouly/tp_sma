class Zombie : public Agent{
    int tempsSansManger;

    public:
    void Manger(Survivant& s);
    void live();
    void TraquerHumain();
    Zombie(int tSM);
    int getTempsSansManger();
    void setTempsSansManger(int tSM);
};