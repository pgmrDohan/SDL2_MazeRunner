typedef struct SDL_Text {
  SDL_Surface *surfaceText;
  SDL_Texture *Text;
  SDL_Rect TextRect;
} SDL_Text;

SDL_Text *SDL_CreateTextRect(SDL_Renderer *renderer, char *textString,
                             SDL_Color fontcolor, int style, int x, int y) {
  SDL_Text *newTextRect = (SDL_Text *)malloc(sizeof(SDL_Text));
  if (style != 0) {
    newTextRect->surfaceText =
        TTF_RenderUTF8_Blended(TITLE_FONT, textString, fontcolor);
  } else {
    newTextRect->surfaceText =
        TTF_RenderUTF8_Blended(FONT, textString, fontcolor);
  }
  newTextRect->Text =
      SDL_CreateTextureFromSurface(renderer, newTextRect->surfaceText);
  newTextRect->TextRect = (SDL_Rect){x, y, 0, 0};
  TTF_SizeText(FONT, textString, &newTextRect->TextRect.w,
               &newTextRect->TextRect.h);
  SDL_FreeSurface(newTextRect->surfaceText);

  return newTextRect;
}