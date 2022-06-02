struct myCmp{
    bool operator()(Person const &p1, Person const &p2){
        return p1.ht < p2.ht;
    }
};