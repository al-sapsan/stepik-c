/**********************************************************************
 * @file script7.cpp
 * @brief Art, Painting, Music class implementation (Embedded C++ style)
 * @version 1.0
 * @date 2025-10-01
 **********************************************************************/

using std::cout;
using std::endl;
using std::string;
// Removed unnecessary includes
// Only required using declarations are added

/********** Class Definition **********/
// == < Art > == //
/**
 * @brief Класс искусства
 * @param stars Количество звезд (оценка)
 */
class Art
{
protected:
    short m_stars{0};

public:
    Art(short st = 0) : m_stars(st) {}

    virtual void set_stars(short vol) { m_stars = vol; }
    short get_stars() const { return m_stars; }
    virtual ~Art() = default;
};

// == < Painting > == //
/**
 * @brief Класс картины
 * @param title Название
 * @param author Автор
 */
class Painting : public Art
{
private:
    std::string m_title;
    std::string m_author;

public:
    Painting(const std::string &title, const std::string &author)
        : m_title(title), m_author(author) {}

    const std::string &get_title() const { return m_title; }
    const std::string &get_author() const { return m_author; }

    virtual ~Painting() override
    {
        std::cout << "~Painting" << std::endl;
    }
};

// == < Music > == //
/**
 * @brief Класс музыки
 * @param title Название
 * @param composer Композитор
 * @param max_stars Максимальное количество звезд
 */
class Music : public Art
{
private:
    std::string m_title;
    std::string m_composer;
    short m_max_stars{5};

public:
    Music(const std::string &title, const std::string &composer)
        : m_title(title), m_composer(composer) {}

    const std::string &get_title() const { return m_title; }
    const std::string &get_composer() const { return m_composer; }

    virtual void set_stars(short vol) override
    {
        m_stars = (vol > m_max_stars) ? m_max_stars : vol;
    }

    virtual ~Music() override
    {
        std::cout << "~Music" << std::endl;
    }
};