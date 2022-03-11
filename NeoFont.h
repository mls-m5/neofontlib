/** @file       NeoFont.h
 *  @brief      Header file for the NeoFont C++ class.
 *  @copyright  (c) 2006 Alquanto. All Rights Reserved.
 */

#pragma once

#include "NeoCharacter.h"

constexpr size_t kNeoFontCharacterCount =
    256; /**< The number of characters in a Neo Font. */

/** Class describing a complete font.
 */
class NeoFont {
public:
    NeoFont();
    NeoFont(const NeoFont &) = default;
    NeoFont(NeoFont &&) = default;
    NeoFont &operator=(const NeoFont &) = default;
    NeoFont &operator=(NeoFont &&) = default;
    ~NeoFont();

    const char *appletName() const;
    const char *appletInfo() const;
    const char *fontName() const;
    const char *version() const;
    int ident() const;
    int height() const;

    const char *setAppletInfo(const char *n);
    const char *setFontName(const char *n);
    const char *setAppletName(const char *n);
    const char *setVersion(const char *v);
    int setIdent(int i);
    int setHeight(int h);

    void clear();

    NeoCharacter *character(int index);

    unsigned int appletSize() const;
    unsigned int encodeApplet(uint8_t *data, unsigned int length) const;
    bool decodeApplet(const uint8_t *data, unsigned int length);

    unsigned int archiveSize() const;
    void loadArchive(const uint8_t *data);
    void saveArchive(uint8_t *data) const;

private:
    /* Do not use pointer member variables here. The loadArchive() and
     * saveArchive() methods both in this class and in NeoFont have a trivial
     * implementation that will need to be significantly more complex if
     * pointers are used.
     */
    std::array<char, 36> m_appletName; // Name seen in AS manager
    std::array<char, 60> m_appletInfo; // Copyright text
    std::array<char, 24> m_fontName;   // Name visible on neo
    int m_versionMajor;
    int m_versionMinor;
    int m_versionBuild;                   /**< Build code (ASCII character). */
    std::array<char, 16> m_versionString; /**< Cached version string. */
    int m_ident;                          /**< 16 bit Unique ID code. */
    int m_height;                         /**< Font height (pixels) */
    std::array<NeoCharacter, kNeoFontCharacterCount> m_characters;

    void remakeVersionString();
    int maxWidth() const;
};
