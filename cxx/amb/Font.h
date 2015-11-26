/**
 * amb/Font.h
 */

#ifndef AMB_FONT_H_
#define AMB_FONT_H_

#include <string>
#include <SFML/Graphics/Font.hpp>
#include <amb/FontNames.h>

namespace amb {

class Font : public sf::Font
{
public:
   static const Font s_luxirb;
   static const Font s_luxirbi;
   static const Font defaults[];

   Font() = delete;
   Font(const std::string& fontFile);
   virtual ~Font() = default;
};

} // End namespace amb

#endif // AMB_FONT_H_
