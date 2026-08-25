<div align="center">

<h1>iRon-Advanced</h1>
Overlays expandidos leves e poderosos para o iRacing<br><br>

[**English**](../../README.md) | [**English (UK)**](../en-GB/README.md) | [**한국어**](../ko/README.md) | [**日本語**](../ja/README.md) | [**简体中文**](../zh/README.md) | [**Deutsch**](../de/README.md) | [**Français**](../fr/README.md) | [**Italiano**](../it/README.md) | **Português** | [**Русский**](../ru/README.md)

</div>

---

Este projeto é uma versão amplamente expandida do overlay original `iRon`. Mantendo a filosofia principal do projeto original — ser extremamente leve e livre de dependências de execução externas —, ele adiciona recursos poderosos e essenciais para jogadores de iRacing.

> **Baseado no projeto original iRon (por lespalt):** [https://github.com/lespalt/iRon](https://github.com/lespalt/iRon)

<br>

### ✨ O que há de diferente em relação ao iRon original?

**1. 💾 Salvamento Automático de Layout Global**
* O iRon original sofria com o reset das posições das janelas toda vez que o aplicativo era reiniciado.
* **iRon-Advanced** salva o layout das coordenadas de tela, tamanhos de janela e estados de exibição dos overlays (Ligado/Desligado) no caminho `Documents\iRon_Advanced\config.json` do Windows. Ao reiniciar, seu último layout é perfeitamente restaurado!

**2. 📊 Classificação e Telemetria Aprimoradas**
* Adicionado um **indicador com a sigla do país em 3 letras** (ex: `[KOR]`, `[USA]`) logo antes do nome do piloto no overlay de Classificação (Standings), facilitando a identificação rápida da origem dos competidores.
* Textos redundantes de modelos de carros foram limpos para um visual extremamente profissional e sem poluição visual.
* Adicionadas **alterações estimadas de iRating em tempo real (+/-)** com base no sistema de classificação Elo diretamente no overlay de Relativos (Relative).

**3. 🚀 Novos Overlays Adicionados:**
* **Spotter Visual Esquerdo e Direito (NOVO):** Avisos visuais para pontos cegos. Os painéis esquerdo e direito são separados e podem ser arrastados/redimensionados de forma independente! Eles piscam em **Amarelo** ou **Vermelho** com base na distância de proximidade real dos carros ao seu lado, permanecendo 100% transparentes quando a pista estiver livre.
* **Radar (Radar de Proximidade):** Um radar de proximidade com visão aérea (top-down) que permanece completamente transparente quando não há carros próximos, evitando poluir sua visão.
* **Aviso de Incidentes (Incidente Inteligente):** Um banner de aviso piscante e exibição de distância exata para acidentes que ocorram a até 150 metros à frente.
* **Tráfego (Tráfego Multiclasse):** Interface dinâmica de bandeira azul com base nas diferenças de ritmo de tempo de volta quando classes mais rápidas se aproximam por trás.

---

# Conteúdo

- [Onde Baixar](#-onde-baixar)
- [Overlays](#-overlays)
  - [*Relative*](#relative)
  - [*DDU*](#ddu)
  - [*Inputs*](#inputs)
  - [*Standings*](#standings)
  - [*Cover*](#cover)
  - [*Spotter (NOVO)*](#spotter-novo)
  - [*Radar (NOVO)*](#radar-novo)
  - [*Aviso de Incidentes (NOVO)*](#aviso-de-incidentes-novo)
  - [*Tráfego Multiclasse (NOVO)*](#trafego-multiclasse-novo)
  - [*Head to Head (NOVO)*](#head-to-head-novo)
  - [*Bomb Avenge (NOVO)*](#bomb-avenge-novo)
- [Instalação e Execução](#-instalacao-e-execucao)
- [Configuração](#️-configuracao)
- [Compilando a partir do Código-Fonte](#️-compilando-a-partir-do-codigo-fonte)
- [Dependências](#-dependencias)

---

## 📥 Onde Baixar

A versão binária mais recente pode ser encontrada [aqui](https://github.com/grandff/iRon-advanced/releases/latest).

<br>

## 📺 Overlays

### *Relative*
Como a caixa de *Relativos* (Relative) no iRacing, mas com informações adicionais, como licença, iRating, voltas completadas desde o último pit stop e **alterações de iRating estimadas em tempo real** para os participantes da classe atual. Você também pode destacar seus amigos adicionando seus nomes a uma lista de amigos.
No topo há um minimapa opcional. Ele pode ser configurado para o modo relativo (seu próprio carro fixado no centro) ou para o modo absoluto (linha de chegada/largada fixada no centro).

![relative](https://github.com/lespalt/iRon/blob/main/relative.png?raw=true)

### *DDU*
Um painel (DDU) que concentra informações importantes para as quais, de outra forma, você teria que navegar por várias caixas no iRacing.
O calculador de combustível mostra a estimativa de voltas restantes, a quantidade de combustível restante, a estimativa de combustível usado por volta, o combustível _adicional_ estimado necessário para terminar a corrida e a quantidade de combustível programada para ser adicionada no próximo pit stop.

![ddu](https://github.com/lespalt/iRon/blob/main/ddu.png?raw=true)

### *Inputs*
Mostra o acelerador/freio/direção em um gráfico em movimento. Extremamente útil para praticar um *trail braking* consistente.

![inputs](https://github.com/lespalt/iRon/blob/main/inputs.png?raw=true)

### *Standings*
Mostra a classificação de todo o grid, incluindo classificação de segurança (Safety Rating), iRating, número de voltas desde o último pit stop ("pit age") e um indicador limpo com a **sigla do país** à esquerda do nome de cada piloto. Útil principalmente durante períodos de bandeira amarela (caution) ou antes da corrida para ter uma noção do nível de competição.

![standings](https://github.com/lespalt/iRon/blob/main/standings.png?raw=true)

### *Cover*
Não há captura de tela para este. É um retângulo preto em branco simples, útil para cobrir painéis distrativos do jogo, como o da Next-Gen da NASCAR.

### *Spotter (NOVO)*
Um spotter visual que desenha retângulos coloridos nas laterais esquerda e direita da sua tela quando há um carro no seu ponto cego.
* Os painéis esquerdo e direito são **configuráveis, móveis e redimensionáveis de forma independente**.
* Exibe uma barra de atenção em **Amarelo** para carros próximos e muda para uma barra de alerta em **Vermelho** brilhante se um carro chegar perigosamente perto (<= 2,2 m).
* Completamente transparente por padrão, tornando-se semitransparente apenas quando a edição de layout estiver ativa.

![spotter](../../screenshot_placeholder_spotter.png)

### *Radar (NOVO)*
Um radar de proximidade que renderiza uma visão aérea (top-down) dos carros ao seu redor.
* Permanece 100% transparente por padrão quando não há carros por perto para manter a clareza da tela.
* Ativa-se e renderiza uma visão aérea dos veículos ao redor assim que eles entram em curto alcance.

![radar](../../screenshot_placeholder_radar.png)

### *Incident Warning (NOVO)*
Um sistema inteligente de aviso de incidentes. Em vez de apenas mostrar um banner genérico de bandeira amarela, este overlay calcula se um carro à sua frente saiu da pista durante uma bandeira amarela ou advertência. Se um carro acidentado ou fora da pista for detectado a até 150 metros à frente, ele renderiza um banner de aviso piscante em destaque especificando a distância até o acidente.

![incident](../../screenshot_placeholder_incident.png)

### *Multiclass Traffic (NOVO)*
Um sistema dinâmico de aviso de bandeira azul para corridas multiclasse. Ele compara os tempos de volta estimados dos carros ao seu redor com o seu. Se um carro de uma classe mais rápida se aproximar por trás dentro de uma diferença de tempo crítica, ele aciona um efeito luminoso progressivo na interface que pisca intensamente em azul/branco para alertá-lo sem bloquear sua visão.

![traffic](../../screenshot_placeholder_traffic.png)

### *Head to Head (NOVO)*
Mostra comparações em tempo real com os pilotos imediatamente à sua frente e atrás de você. Mostra posição, nome, intervalo (gap), tempos de volta e tempos de setor (S1, S2, S3) da última volta completada.
* Altamente útil para monitorar onde você está perdendo ou ganhando tempo em relação aos seus rivais diretos.
* Apresenta uma faixa de destaque proeminente para a sua própria linha.

### *Bomb Avenge (NOVO)*
Exibe informações de rastreamento em tempo real do piloto que bateu em você.
* É acionado automaticamente quando uma colisão aumenta sua contagem de incidentes.
* Mostra o nome do infrator, sua posição atual na corrida e a distância de intervalo em tempo real em metros.
* No overlay de Relativos (*Relative*), a linha do piloto infrator piscará em vermelho, o fundo do número do carro dele ficará vermelho e seu nome receberá o prefixo `[BOMB]`.

---

## 🚀 Instalação e Execução

O aplicativo não requer instalação. Basta copiar o executável (`.exe`) para uma pasta de sua preferência.

Para usá-lo, basta dar um duplo clique no executável. Não importa se você faz isso antes ou depois de iniciar o iRacing. Uma janela de console aparecerá indicando que o iRon está em execução. Assim que você estiver no carro no iRacing, os overlays deverão aparecer. Recomendamos fortemente executar o iRacing no modo **Janela Sem Bordas** (Borderless Window).

---

## ⚙️ Configuração

Para posicionar e redimensionar os overlays, pressione **ALT-J**. Isso ativará o modo de edição de layout, no qual você pode mover os overlays com o mouse e redimensioná-los arrastando o canto inferior direito. Pressione **ALT-J** novamente para retornar ao modo normal.

Os overlays podem ser ativados e desativados em tempo de execução usando as teclas de atalho exibidas durante a inicialização. Todas as teclas de atalho são configuráveis.

Seu layout e configurações são salvos de forma automática e global em:
`Documents\iRon_Advanced\config.json`

### Mapa de Teclas de Atalho Padrão:
* **ALT-J**: Modo de Mover e Redimensionar (Edição de Layout)
* **Ctrl-Space**: Alternar Classificação
* **Ctrl-1**: Alternar DDU (Painel)
* **Ctrl-2**: Alternar Entradas (Gráfico de Pedais)
* **Ctrl-3**: Alternar Caixa de Relativos (Relative)
* **Ctrl-4**: Alternar Caixa de Cobertura (Cover)
* **Ctrl-5**: Alternar Spotters (Esquerdo/Direito sincronizados)
* **Ctrl-6**: Alternar Radar de Proximidade
* **Ctrl-7**: Alternar Aviso de Incidentes
* **Ctrl-8**: Alternar Painel de Pneus
* **Ctrl-9**: Alternar Widget Head to Head
* **Ctrl-0**: Alternar Widget Bomb Avenge
* **Ctrl-Shift-D**: Alternar Modo de Exibição Global (Apenas Corrida / Apenas Replay / Ambos)

---

## 🛠️ Compilando a partir do Código-Fonte

Este aplicativo foi desenvolvido com o Visual Studio 2022. A versão gratuita deve ser suficiente, embora não tenhamos verificado isso. Os arquivos de projeto/solução devem funcionar perfeitamente de imediato. Dependendo da sua configuração do Visual Studio, pode ser necessário instalar pré-requisitos adicionais (bibliotecas estáticas) necessários para compilar aplicativos DirectX.

---

## 📦 Dependências

Não há dependências de execução além dos componentes padrão do Windows, como o DirectX. Esses componentes já devem estar presentes na maioria, senão em todos os sistemas capazes de rodar o iRacing. As dependências de compilação (principalmente o SDK do iRacing e picojson) são mantidas ao mínimo e estão inclusas no repositório.
