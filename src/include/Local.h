//
// Created by skidr on 06/05/2020.
//

#ifndef MEETUP_RIDER_LOCAL_H
#define MEETUP_RIDER_LOCAL_H

#include <string>

/**
 * @brief Classe Local
 * Guarda as infomações de um Local
 */
class Local {
    int id;
    std::string nome; //!< nome do local
    double x;
    double y;
public:
    /**
     * @brief Construtor padrão de Local
     * Inicia o atributo nome como "undefined"
     */
    Local();

    Local(int id, const std::string &nome, double x, double y);

    /**
     * @brief Método GET para o nome
     * @return nome do local
     */
    const std::string &getNome() const;

    /**
     * @brief Método SET para o nome
     * @param nome novo nome do local
     */
    void setNome(const std::string &nome);

    int getId() const;

    double getX() const;

    double getY() const;
};


#endif //MEETUP_RIDER_LOCAL_H
