class Agent{
        int force;
        int dureeDeVie;
    public:
        void virtual live() = 0;
        Agent(int f, int dDV);
        int getForce();
        int getDureeDeVie();
        void setForce(int nf);
        void setDureeDeVie(int ndDV);
};