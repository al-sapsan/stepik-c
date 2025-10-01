/**********************************************************************
 * @file script8.cpp
 * @brief Life inheritance tree
 * @version 1.0
 * @date
 **********************************************************************/

enum type_life
{
    lf_protists = 1,
    lf_plants = 2,
    lf_animals = 3,
    lf_mosses = 4,
    lf_flowering = 5,
    lf_worms = 6,
    lf_mammals = 7,
    lf_human = 8,
    lf_monkeys = 9
};

/********** Class Definition **********/

// == < Protists > == //
class Protists
{
    const type_life m_type{lf_protists};

public:
    virtual const type_life get_type() const { return m_type; }
    virtual ~Protists() = default;
};

// == < Plants > == //
class Plants : public Protists
{
    const type_life m_type{lf_plants};

public:
    virtual const type_life get_type() const override { return m_type; }
};

// == < Mosses > == //
class Mosses : public Plants
{
    const type_life m_type{lf_mosses};

public:
    virtual const type_life get_type() const override { return m_type; }
};

// == < Flowering > == //
class Flowering : public Plants
{
    const type_life m_type{lf_flowering};

public:
    virtual const type_life get_type() const override { return m_type; }
};

// == < Animals > == //
class Animals : public Protists
{
    const type_life m_type{lf_animals};

public:
    virtual const type_life get_type() const override { return m_type; }
};

// == < Worms > == //
class Worms : public Animals
{
    const type_life m_type{lf_worms};

public:
    virtual const type_life get_type() const override { return m_type; }
};

// == < Mammals > == //
class Mammals : public Animals
{
    const type_life m_type{lf_mammals};

public:
    virtual const type_life get_type() const override { return m_type; }
};

// == < Human > == //
class Human : public Mammals
{
    const type_life m_type{lf_human};

public:
    virtual const type_life get_type() const override { return m_type; }
};

// == < Monkeys > == //
class Monkeys : public Mammals
{
    const type_life m_type{lf_monkeys};

public:
    virtual const type_life get_type() const override { return m_type; }
};

/********** Main Function **********/

int main(void)
{
    Protists *life[] = {
        new Plants(), new Flowering(), new Flowering(), new Monkeys(),
        new Animals(), new Worms(), new Worms(), new Human(),
        new Monkeys(), new Mammals(), new Animals(), new Animals()};

    // Count Animals and Monkeys
    int n_animals = 0, n_monkeys = 0;
    for (size_t i = 0; i < sizeof(life) / sizeof(life[0]); ++i)
    {
        if (dynamic_cast<Animals *>(life[i]) && life[i]->get_type() == lf_animals)
            ++n_animals;
        if (dynamic_cast<Monkeys *>(life[i]))
            ++n_monkeys;
    }

    Animals *lf_lst1[n_animals];
    Monkeys *lf_lst2[n_monkeys];
    int idx_animals = 0, idx_monkeys = 0;
    for (size_t i = 0; i < sizeof(life) / sizeof(life[0]); ++i)
    {
        if (dynamic_cast<Animals *>(life[i]) && life[i]->get_type() == lf_animals)
            lf_lst1[idx_animals++] = static_cast<Animals *>(life[i]);
        if (dynamic_cast<Monkeys *>(life[i]))
            lf_lst2[idx_monkeys++] = static_cast<Monkeys *>(life[i]);
    }

    __ASSERT_TESTS__

    for (size_t i = 0; i < sizeof(life) / sizeof(life[0]); ++i)
        delete life[i];

    return 0;
}