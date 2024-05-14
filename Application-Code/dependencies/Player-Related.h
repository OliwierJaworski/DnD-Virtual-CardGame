#ifndef player_related
#define player_related

struct Inventory{
  struct item_T* items;
  struct Coin_T* Coins;
  float weight;
};
extern struct Inventory Player_inv;

#endif
