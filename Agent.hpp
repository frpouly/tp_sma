class Agent{
        int force;
        int dureeDeVie;
    public:
        void virtual live();
        Agent(int f, int dDV);
        int getForce();
        int getDureeDeVie();
        void setForce();
        void setDureeDeVie();
};