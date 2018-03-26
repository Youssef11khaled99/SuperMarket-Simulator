// will be passed as a parameter to the function sort()

class sortByName{
    bool order;
    public:
    sortByName(bool order) {this->order = order;}
    bool operator()(const Item& RHS, const Item& LHS){
        if (order) return (RHS.getName() > LHS.getName());
        else return (RHS.getName() < LHS.getName());
    }
};

class sortByCategory{
    bool order;
    public:
    sortByCategory(bool order) {this->order = order;}
    bool operator()(const Item& RHS, const Item& LHS){
        if (order) return (RHS.getCategory() > LHS.getCategory());
        else return (RHS.getCategory() < LHS.getCategory());
    }
};

class sortByAmount{
    bool order;
    public:
    sortByAmount(bool order) {this->order = order;}
    bool operator()(const Item& RHS, const Item& LHS){
        if (order) return (RHS.getAmount() > LHS.getAmount());
        else return (RHS.getAmount() < LHS.getAmount());
    }
};

class sortByPrice{
    bool order;
    public:
    sortByPrice(bool order) {this->order = order;}
    bool operator()(const Item& RHS, const Item& LHS){
        if (order) return (RHS.getPrice() > LHS.getPrice());
        else return (RHS.getPrice() < LHS.getPrice());
    }
};
