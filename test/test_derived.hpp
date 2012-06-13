// Testing derived class serialization

class BaseClass
{
    int a;

public:
    BaseClass() : a(124) {};

    template <typename Archive>
    void Serialize(Archive& ar)
    {
        ar & TAG(a);
    }
};

class DerivedClass : public BaseClass
{
    bool e;
    char c;

public:
    DerivedClass() : e(true), c('z') {};

    template <typename Archive>
    void Serialize(Archive& ar)
    {
        ar & TAG(s11n::BaseObject<BaseClass>(*this));
        ar & TAG(e) & TAG(c);
    }
};

