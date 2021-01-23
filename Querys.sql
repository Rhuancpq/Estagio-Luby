-- 2.1 Crie uma query para selecionar todas as pessoas 'tabela_pessoa' 
-- e os respectivos eventos 'tabela_evento' o qual elas participam.
SELECT *
FROM tabela_pessoa AS P JOIN tabela_evento AS E
ON P.ID = E.pessoa_id;


-- 2.2 Crie uma query para selecionar todas as pessoas
-- 'tabela_pessoa' com sobrenome 'Doe'.
SELECT *
FROM tabela_pessoa
WHERE nome LIKE '%Doe';

-- 2.3 Crie uma query para adicionar um novo evento 
-- 'tabela_evento' e relacionar à pessoa 'Lisa Romero'.
INSERT INTO tabela_evento(evento, pessoa_id) VALUES
("Processo Seletivo", 5);

-- 2.4 Crie uma query para atualizar 'Evento D' na 
-- 'tabela_evento' e relacionar à pessoa 'Joh Doe'
UPDATE tabela_evento
SET pessoa_id = 1
WHERE id = 4;

-- 2.5 Crie uma query para remover o
-- 'Evento B' na 'tabela_evento'.
DELETE FROM tabela_evento
WHERE id = 2;

-- 2.6 Crie uma query para remover todas as pessoas
-- 'tabela_pessoa' que não possuem
-- eventos 'tabela_evento' relacionados.
DELETE P FROM
tabela_pessoa AS P LEFT JOIN tabela_evento AS E
ON P.id = E.pessoa_id
WHERE E.pessoa_id IS NULL;

-- 2.7 Crie uma query para alterar a tabela
-- 'tabela_pessoa' e adicionar a coluna 'idade' (int)
ALTER TABLE tabela_pessoa
ADD idade INT;

-- 2.8 Crie uma query para criar uma tabela
-- chamada 'tabela_telefone' 
-- que pertence a uma pessoa com seguintes campos:\
-- id: int (PK)
-- telefone: varchar(200)
-- pessoa_id: int(FK)
CREATE TABLE tabela_telefone(
    id INT PRIMARY KEY,
    telefone VARCHAR(200),
    pessoa_id INT,
    FOREIGN KEY(pessoa_id) REFERENCES tabela_pessoa(id)
);

-- 2.9 Crie uma query para criar uma índice do 
-- tipo único na coluna telefone da 'tabela_telefone'.
ALTER TABLE tabela_telefone
ADD UNIQUE(telefone);

-- 2.10 Crie uma query para remover a 'tabela_telefone'.
DROP TABLE tabela_telefone;