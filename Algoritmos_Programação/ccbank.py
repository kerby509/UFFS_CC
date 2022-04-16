
class agenda:
  nome=''
  sobrenome=''
  cpf=0
  numero_do_cartao=0
  fatura_do_cartao=0
  limite_de_credito=0
  senha=0
  compras=[]


class compra:
  tipo=''
  valor=0

  ## função para listar todos os contatos cadastrados
def listaContatos(contatos):

    print("****Os nossos clientes****")
    for i in range(len(contatos)):
        print()
        print('Nome: ',contatos[i].nome)
        print('sobrenome: ',contatos[i].sobrenome)
        print('Cpf: ',contatos[i].cpf)
        print('Numero do cartao: ',contatos[i].numero_do_cartao)
        print('Fatura do cartao: ',contatos[i].fatura_do_cartao)
        print('Limite de credito: ',contatos[i].limite_de_credito)
        print('senha: ',contatos[i].senha)
        print()


def verCartao(conta,lc):
  for i in range(len(lc)):
    if lc[i].numero_do_cartao==conta:
      return False
  return True
   
    # função para procurar um nome na lista de contatos (retorna a posição do nome)
def procuraContato(nome, contatos):
  for i in range(len(contatos)):
    if contatos[i].nome==nome:
      return i #posição do nome na lista
  return -1 # indica que o nome não foi encontrado

  ## insere contato
def insereContato(cliente):
  cliente.nome=input('Nome : ')
  cliente.sobrenome=input('sobrenome: ')

  valor = input("Digite o CPF: ")
  cpf = list(map(int, valor))
  if validaCPF(cpf):
    print("CPF valido")
    cliente.cpf = int("".join(str(x) for x in cpf))
  else:
    print("CPF nao e valido")
    cliente.nome='erro'
    return

  cartao = int(input('Numero do cartao: '))
  if verCartao(cartao,lcontato)==True:
    cliente.numero_do_cartao = cartao
  else:
    print('cartao ja cadastrado')
    cliente.nome='erro'
    return
  cliente.fatura_do_cartao=float(input('Fatura do cartao: '))
  
  limite = float(input('Limite de credito: ' ))
  # validação para o limite
  if 0 < limite < 999999:
    cliente.limite_de_credito = limite
  else:
    while limite < 0 or limite > 999999:
      print('Por favor Informe um valor entre 0 e 999999!')
      limite = float(input('limite de credito: '))
  
  cliente.limite_de_credito = limite
  senha = ''
  while True:  
    senha = input('Digite a senha: ')
    if len(senha) == 6:
        senhaValida = True
        for i in range(0,len(senha)):
            if senha[i].isdigit() == False:
                senhaValida = False
                break
                
        if senhaValida:
            break;
        else:
            print("\nSenha invalida, deve conter apenas numeros. Por favor digite novamente\n\n")
    else:
        print("\nPor favor, digite uma senha de 6 digitos\n\n")
        
  cliente.senha = senha
  
  # Ok, insere contato

  print( )
  print('Um novo cliente foi adicionado com successo')

#cpf valida
def validaCPF(cpf):
  parte_inicial = cpf[0:9]
  num = 10
  soma = 0
    # Faz a multiplicação
  for i in range(0,len(parte_inicial)):
      soma += (parte_inicial[i] * num)
      num -= 1       
  
  digito_um = 0

    # Determina o valor do primeiro digito
  resto = soma % 11
  if resto >= 2:
      digito_um = 11-resto
        
    # Anexa o primeiro digito
  parte_inicial.append(digito_um)

    # Faz a multiplicação incluindo o novo digito
  num = 11
  soma = 0
  for i in range(0,len(parte_inicial)):
      soma += parte_inicial[i] * num
      num -= 1      
    
  digito_dois = 0
    
    # Determina o valor do segundo digito
  resto = soma % 11
  if resto >= 2:
      digito_dois = 11-resto
        
    # Anexa segundo digito
  parte_inicial.append( digito_dois )
    
    # Se sao iguais, então é valido
  return (cpf == parte_inicial)
  
  #altera dados
def alterContato(pos,contatos):
  print()
  print('Nome: ',contatos[pos].nome)
  print('Sobrenome: ',contatos[pos].sobrenome)
  print('Cpf: ',contatos[pos].cpf)
  print('Numero do cartao: ',contatos[pos].numero_do_cartao)
  print('Fatura do cartao: ',contatos[pos].fatura_do_cartao)
  print('Limite de credito: ',contatos[pos].limite_de_credito)
  print('Senha: ',contatos[pos].senha)
  print()
  print('digite 1 para altera Nome: ')
  print('digite 2 para altera Sobrenome: ')
  print('digite 3 para altera Cpf: ')
  print('digite 4 para altera o numero do cartao: ')
  print('digite 5 para altera o fatura do cartao: ')
  print('digite 6 para altera o limite de credito: ')
  print('digite 7 para altera a senha: ')
  print()
  alteracao=int(input('digite a opcao desejada:'))
  if alteracao==1:
    novo_nome=input('Novo nome: ')
    contatos[pos].nome=novo_nome
  elif alteracao==2:
    novo_sobrenome=input('Novo sobrenome: ')
    contatos[pos].sobrenome=novo_sobrenome
  elif alteracao==3:
    novo_cpf=input('Novo cpf: ')
    contatos[pos].cpf=novo_cpf
  elif alteracao==4:
    novo_numero_do_cartao=input('Novo numero da conta: ')
    contatos[pos].numero_do_cartao=novo_numero_do_cartao
  elif alteracao==5:
    novo_fatura_do_cartao=input('Novo fatura do cartao: ')
    contatos[pos].fatura_do_cartao=novo_fatura_do_cartao
  elif alteracao==6:
    novo_limite_de_credito=input('Novo limite de credito: ')
    contatos[pos].limite_de_credito=novo_limite_de_credito
  elif alteracao==7:
    nova_senha=input('Nova senha: ')
    contatos[pos].senha=nova_senha
  
  print()
  print('Nome: ',contatos[pos].nome)
  print('Sobrenome: ',contatos[pos].sobrenome)
  print('Cpf: ',contatos[pos].cpf)
  print('Numero do cartao: ',contatos[pos].numero_do_cartao)
  print('Fatura do cartao: ',contatos[pos].fatura_do_cartao)
  print('Limite de credito: ',contatos[pos].limite_de_credito)
  print('Senha: ',contatos[pos].senha)
  print()
  print('Dados alterados com sucesso')
  
  #
def excluiContato(pos,contatos):
  contatos.remove(contatos[pos])
  print()
  print('Dados excluidos com sucesso')

 
 # funcao pra altera limite

def alteralimite(lc):
  cartao=int(input('Numero do cartao: '))
  pos=-1
  for i in range(len(lc)):
    if lc[i].numero_do_cartao==cartao:
      pos=i
      break
  if pos==-1:
    print('cartao nao cadastrado')
    return
  lc[pos].limite_de_credito=float(input('Novo limite: '))

## função de menu
def menu():
  print(' ***Sistema CCBank*** ')
  print('='*30)
  print()
  print('1 - Inserir')
  print('2 - Consultar')
  print('3 - Alterar')
  print('4 - Excluir')
  print('5 - Listar todos')
  print('6 - alterar limite ')
  print('7 - Cadastrar compra')
  print('8 - Sair')
  return int(input(': '))


  ##
lcontato=[] # armazena a lista de contatos
categorias_compra = ["viagem","Farmacia", "supermercado","alimentação", "Carro", "Outros" ]       
def cadastra_compra(lc):
  cartao=int(input('Numero do cartao: '))
  pos=-1
  for i in range(len(lc)):
    if lc[i].numero_do_cartao==cartao:
      pos=i
      break
  if pos==-1:
    print('cartao nao cadastrado')
    return

  senha=input('digite a senha: ')
  if lc[pos].senha!=senha:
    print('invalida')
    return
  
  categoria_opcao = -1                
  while categoria_opcao != len(categorias_compra):
    i = 0
            
    print( "\nCategoria de compras:" )
    for i in range(0, len(categorias_compra)):
      print( "%d. %s" % (i,categorias_compra[i]) )
    print( "%d. <Cancelar compra>" % (i+1) )            
            
    categoria_opcao = int(input("\n> "))
    if categoria_opcao >=6:
      return
    cp=compra()
    cp.tipo=categorias_compra[categoria_opcao]

    valor = -1
    print( "Digite o valor da compra:" )
    while valor < 0:
      valor = float(input())     
    if lc[pos].limite_de_credito<lc[pos].fatura_do_cartao+valor:
      print('nao tem mais limite')
      return
    lc[pos].fatura_do_cartao+=valor
    cp.valor=valor
    lc[pos].compras.append(cp)
    print( "Compra realizada com sucesso! (Categoria: %s, Valor: %d)" % (categorias_compra[categoria_opcao], valor) )
    

# Menu principal
op=1
senha='549053'
while op!=8:
  op=menu()
  if op==1:
    s=input('Digite a senha: ')
    if s==senha:
      newc=agenda()
      insereContato(newc)
      if newc.nome!='erro':
        lcontato.append(newc)
      else:
        print('Nao foi possivel insere contato')
    else:
      print('Senha incorreto')
  elif op==2:
    nome=input('Nome para procurar: ')
    pos=procuraContato(nome,lcontato)
    if pos!=-1: # encontrou o nome?
      print('Nome : ',lcontato[pos].nome)
      print('Sobrenome: ',lcontato[pos].sobrenome)
      print('CPF: ',lcontato[pos].cpf)
      print('Numero do cartao: ',lcontato[pos].numero_do_cartao)
      print('Fatura do cartao: ',lcontato[pos].fatura_do_cartao)
      print('Limite de credito: ',lcontato[pos].limite_de_credito)
      print('Senha: ',lcontato[pos].senha)
      
      print("Gastos acumulados:")      
      for categoria in categorias_compra:
        print("--------------------------")
        print( categoria )
        print("--------------------------")
        soma = 0
        for compra in lcontato[pos].compras:
          if compra.tipo == categoria:
            soma += compra.valor
        print("Total: %d\n" % soma)

    
    else:
      print('Contato não encontrado!')
  elif op==3:
    nome=input('Nome a ser alterado: ')
    pos=procuraContato(nome,lcontato)
    if pos!=-1:
      alterContato(pos,lcontato)
    else:
      print('Contato não encontrado')
  elif op==4:
    nome=input('nome a ser excluído: ')
    pos=procuraContato(nome,lcontato)
    if pos!=-1:
      excluiContato(pos,lcontato)
    else:
      print('Contato não encontrado')
  elif op==5:
    listaContatos(lcontato)
  elif op==6:
    s=input('Digite a senha: ')
    if s==senha:
      alteralimite(lcontato)
    else:
      print('senha de usario root e invalido')
  elif op==7:
    cadastra_compra(lcontato)
print('*** Obrigado por Utilizar Nosso Sistema ***')