class Agent{
        int force;
        int dureeDeVie;
    public:
        virtual void live() = 0;
        Agent(int f, int dDV);
        int getForce();
        int getDureeDeVie();
        void setForce(int nf);
        void setDureeDeVie(int ndDV);
		virtual char affichageA() = 0;
};