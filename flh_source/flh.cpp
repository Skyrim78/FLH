#include "flh.h"
#include "ui_flh.h"
#include <QCryptographicHash>

flh::flh(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::flh)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager();

    makeRequest();
}

flh::~flh()
{
    delete ui;
}

void flh::makeRequest()
{
    QString _token = "4009252350133548";
    QString _key = "6079ac7d7fa7c2294a6b";

    QString _url = "https://api.freelancehunt.com/projects";
    QString _method = "GET";
    QString _postParam = "";

    QString _getReg(QString("%1%2%3").arg(_url).arg(_method).arg(_postParam));

    QCryptographicHash my_hash(QCryptographicHash::Sha256);
    my_hash.addData(_key.toUtf8());


    QByteArray _userPWD;
    _userPWD.append(QString("%1:")
                    .arg(_token));
    _userPWD.append(hmac_sha1(_getReg, _key));
    qDebug() << _userPWD;

    QSslConfiguration ssl_config = QSslConfiguration::defaultConfiguration();
    ssl_config.setProtocol(QSsl::AnyProtocol);
    req.setSslConfiguration(ssl_config);

    req.setUrl(_url);
//    req.setAttribute("HEADER", 1);
    req.setRawHeader(QByteArray("HEADER"), QByteArray("1"));
    req.setRawHeader(QByteArray("RETURNTRANSFER"), QByteArray("1"));
    req.setRawHeader(QByteArray("USERPWD"), _userPWD);
    req.setRawHeader(QByteArray("URL"), _url.toUtf8());
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(readAnswer(QNetworkReply*)));
    manager->sendCustomRequest(req,  hmac_sha1(_getReg, _key));

    //--

    qDebug() << hmac_sha1(_getReg, _key).toBase64();//my_hash.hash(_getReg.toUtf8(), QCryptographicHash::Sha256).toHex();
}

void flh::readAnswer(QNetworkReply *reply)
{
    if (!reply->error()){
        qDebug() << "Reply: "<< reply->readAll();
    } else {
        qDebug() << "Error:" << reply->errorString();
    }
}


QByteArray flh::hmac_sha1(const QString &key, const QString &secret) {
   // Length of the text to be hashed
   int text_length;
   // For secret word
   QByteArray K;
   // Length of secret word
   int K_length;
   K_length = secret.size();
   text_length = key.size();

   // Need to do for XOR operation. Transforms QString to
   // unsigned char

   K = secret.toUtf8();

   // Inner padding
   QByteArray ipad;
   // Outer padding
   QByteArray opad;

   // If secret key > 64 bytes use this to obtain sha1 key
   if (K_length > 64) {
      QByteArray tempSecret;

      tempSecret.append(secret);

      K = QCryptographicHash::hash(tempSecret, QCryptographicHash::Sha1);
      K_length = 20;
   }

   // Fills ipad and opad with zeros
   ipad.fill(0, 64);
   opad.fill(0, 64);

   // Copies Secret to ipad and opad
   ipad.replace(0, K_length, K);
   opad.replace(0, K_length, K);

   // XOR operation for inner and outer pad
   for (int i = 0; i < 64; i++) {
      ipad[i] = ipad[i] ^ 0x36;
      opad[i] = opad[i] ^ 0x5c;
   }

   // Stores hashed content
   QByteArray context;

   // Appends XOR:ed ipad to context
   context.append(ipad, 64);
   // Appends key to context
   context.append(key);

   //Hashes inner pad
   QByteArray Sha1 = QCryptographicHash::hash(context, QCryptographicHash::Sha1);

   context.clear();
   //Appends opad to context
   context.append(opad, 64);
   //Appends hashed inner pad to context
   context.append(Sha1);

   Sha1.clear();

   // Hashes outerpad
   Sha1 = QCryptographicHash::hash(context, QCryptographicHash::Sha1);

   // String to return hashed stuff in Base64 format
  // QByteArray str(Sha1.toBase64());

   return Sha1.toBase64();//str;
}
