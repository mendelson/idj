# Lista de Variáveis da Classe Bullet

#### Classes:

|Nome|Avaliação do nome|Novo nome|
|---	|---	|---	|
|Bullet|O nome Bullet segue os padrões estabelicidos pela folha de estilo|Continuará como Bullet|

#### Métodos:

|Nome|O que a função faz|Avaliação do nome|Novo nome|Obs:|
|---	|---	|---	|---	|---  |
|Bullet()|Metodo construtor da classe|Possui o mesmo nome da classe, que segue os padrões da folha de estilo|Continuará como Bullet()||
|Update()|Atualiza posição da bala no jogo|Nome pouco intuitivo|UpdatePosition()||
|Render()|reenderiza a bala|Bom nome, de acordo com a folha de estilo|Continuará como Render()||
|IsDead()|Verifica se a distancia chegou a zero|Pouco intuitivo, utiliza do verbo morto para se referir a um objeto|GotToDestiny()||
|getSprite()|Retorna o valor do sprite|O nome não segue a folha de estilo, começa com letra minúscula|GetSprite()||
|Is()|Verifica o tipo do objeto|Nome da classe é pouco intuitivo, o verbo 'é' não indentifica o que esse metodo faz|Type()|Método sobreescrito da claasse pai, para modifica-lo é necessário modificar a classe GameObject e todas as classes filhas de GameObject|
|NotifyCollision()|Notifica a colição com um Player|Nome bem definido, descreve bem a função|Continuará como NotifyCollision()|||

#### Variáveis:

|Nome|Avaliação do nome|Novo nome|
|---	|---	|---	|
|alturaInicial|O nome está em português|initialHight|
|planet|Está de acordo com a folha de estilo|Continuará planet|
|sp|É apenas uma sigla, nome de difícil entendimento|sprite|
|speed|Bom nome, indica a velocidade da bala|Continuará como speed|
|distanceLeft|Bom nome|Continuará como distanceLeft|
|angle|De acordo com a folha de estilo|Continuará como angle|
|frameCount|Segue o padrão de nomes estabelecidos|Continuará como frameCount|

#### Constantes a serem criadas:

|Nome|Valor|Motivo|
|---	|---	|---	|
|PI|3.14159265359|Presença em contas no código|
|HALF_CIRCLE|180|Presença em contas no código|
