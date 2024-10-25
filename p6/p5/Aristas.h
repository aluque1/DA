template <typename Valor>
class Arista
{
public:
  Arista(int v, int w, Valor valor);
  int uno() const;
  int otro(int u) const;
  Valor valor() const;
  bool operator<(Arista<Valor> const &b) const;
  bool operator>(Arista<Valor> const &b) const;
};