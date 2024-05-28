// Utility - helper functions
const generateId = () => Math.random().toString(16).slice(2).toString();

// Enums ->
enum PaymentMethod {
  CARD = "CARD",
  UPI = "UPI",
  NET_BANKING = "NET_BANKING",
}
enum Bank {
  HDFC = "HDFC",
  UBI = "UBI",
  PNB = "PNB",
}
enum PaymentStatus {
  IN_PROGRESS = "IN_PROGRESS",
  ERROR = "ERROR",
  SUCCESS = "SUCCESS",
}

// Types ->
// PG Specific
interface PGConfig {
  percentage: number;
  bank: Bank;
  usage: number;
}
interface PaymentGateway {
  clients: Client[];
  banks: Bank[];
  routerConfig: Map<PaymentMethod, PGConfig[]>;
}

// Client Specific
interface Client {
  readonly name: string;
  optedPaymentMethods: PaymentMethod[];
}

// Payment method specific form data
interface Card {
  type: PaymentMethod.CARD;
  cardNumber: string;
  CVV: string;
  cardExpiryDate: string;
  holderName: string;
}

interface UPI {
  type: PaymentMethod.UPI;
  upiId: string;
}

interface NetBanking {
  type: PaymentMethod.NET_BANKING;
  username: string;
  password: string;
}

// Transactions
interface Transaction {
  id: string; // uuid
  paymentMethod: PaymentMethod;
  client: string;
  amount: number;
  bank: Bank;
  status: PaymentStatus;
}

class TransactionRepository {
  private Transactions: Transaction[] = [];
  constructor() {}

  public startTransaction(
    id: string,
    paymentMethod: PaymentMethod,
    client: string,
    amount: number,
    bank: Bank
  ): Transaction {
    try {
      const transaction: Transaction = {
        id,
        paymentMethod,
        client,
        amount,
        bank,
        status: PaymentStatus.IN_PROGRESS,
      };
      this.Transactions.push(transaction);
      return transaction;
    } catch (err) {
      throw err;
    }
  }

  public completeTransaction(id: string): Transaction {
    try {
      const transactionIdx: number = this.Transactions.findIndex(
        (transaction: Transaction) => transaction.id === id
      );
      if (transactionIdx >= 0) {
        this.Transactions[transactionIdx].status = PaymentStatus.SUCCESS;
      }
      return this.Transactions[transactionIdx];
    } catch (err) {
      throw err;
    }
  }

  public failTransaction(id: string): Transaction {
    try {
      const transactionIdx: number = this.Transactions.findIndex(
        (transaction: Transaction) => transaction.id === id
      );
      if (transactionIdx >= 0) {
        this.Transactions[transactionIdx].status = PaymentStatus.ERROR;
      }
      return this.Transactions[transactionIdx];
    } catch (err) {
      throw err;
    }
  }
}

class CardService {
  constructor(
    private hdfcService: HDFCService,
    private pnbService: PNBService,
    private ubiService: UBIService
  ) {}

  private validatePaymentData(paymentData: Card): boolean {
    try {
      // TODO
      return true;
    } catch (err) {
      throw err;
    }
  }

  public carryTransaction(
    bank: Bank,
    amount: number,
    paymentData: Card
  ): boolean {
    try {
      if (this.validatePaymentData(paymentData)) {
        switch (bank) {
          case Bank.HDFC:
            this.hdfcService.makeTransaction(
              amount,
              paymentData.cardNumber,
              paymentData.cardExpiryDate,
              paymentData.CVV,
              paymentData.holderName
            );
            return true;
          case Bank.PNB:
            this.pnbService.makeTransaction(
              amount,
              paymentData.cardNumber,
              paymentData.cardExpiryDate,
              paymentData.CVV,
              paymentData.holderName
            );
            return true;
          case Bank.UBI:
            this.ubiService.makeTransaction(
              amount,
              paymentData.cardNumber,
              paymentData.cardExpiryDate,
              paymentData.CVV,
              paymentData.holderName
            );
            return true;
          default:
            const bankFailSafe: never = bank;
            return false;
        }
      }
      throw new Error("Wrong payment data");
    } catch (err) {
      throw err;
    }
  }
}

class UpiService {
  constructor(private npciService: NPCIService) {}

  private validateUPI(upiId: string): boolean {
    // validate upi id
    return true;
  }

  public carryTransaction(amount: number, upiId: string): boolean {
    try {
      if (this.validateUPI(upiId)) {
        this.npciService.makeTransaction(amount, upiId);
        return true;
      }
      throw new Error("Invalid UPI ID");
    } catch (err) {
      throw err;
    }
  }
}

class NetBankingService {
  constructor(
    private hdfcService: HDFCService,
    private pnbService: PNBService,
    private ubiService: UBIService
  ) {}

  private validatePaymentData(paymentData: NetBanking): boolean {
    try {
      // TODO
      return true;
    } catch (err) {
      throw err;
    }
  }

  public carryTransaction(
    bank: Bank,
    amount: number,
    paymentData: NetBanking
  ): boolean {
    try {
      if (this.validatePaymentData(paymentData)) {
        switch (bank) {
          case Bank.HDFC:
            this.hdfcService.makeTransaction(
              amount,
              paymentData.username,
              paymentData.password
            );
            return true;
          case Bank.PNB:
            this.pnbService.makeTransaction(
              amount,
              paymentData.username,
              paymentData.password
            );
            return true;
          case Bank.UBI:
            this.ubiService.makeTransaction(
              amount,
              paymentData.username,
              paymentData.password
            );
            return true;
          default:
            const bankFailSafe: never = bank;
            return false;
        }
      }
      throw new Error("Wrong payment data");
    } catch (err) {
      throw err;
    }
  }
}

class TransactionService {
  constructor(
    private transactionRepository: TransactionRepository,
    private cardService: CardService,
    private upiService: UpiService,
    private netBankingService: NetBankingService
  ) {}

  public makeTransaction(
    paymentData: Card | UPI | NetBanking,
    paymentMethod: PaymentMethod,
    client: string,
    amount: number,
    bank: Bank
  ): boolean {
    const transactionId: string = generateId();
    try {
      switch (paymentMethod) {
        case PaymentMethod.CARD:
          this.transactionRepository.startTransaction(
            transactionId,
            PaymentMethod.CARD,
            client,
            amount,
            bank
          );
          if (paymentData.type === PaymentMethod.CARD) {
            const transactionStatus: boolean =
              this.cardService.carryTransaction(bank, amount, paymentData);
            if (transactionStatus) {
              this.transactionRepository.completeTransaction(transactionId);
            }
            return transactionStatus;
          } else {
            throw new Error("Payment Data is invalid");
          }
        case PaymentMethod.UPI:
          this.transactionRepository.startTransaction(
            transactionId,
            PaymentMethod.UPI,
            client,
            amount,
            bank
          );
          if (paymentData.type === PaymentMethod.UPI) {
            const transactionStatus: boolean = this.upiService.carryTransaction(
              amount,
              paymentData.upiId
            );
            if (transactionStatus) {
              this.transactionRepository.completeTransaction(transactionId);
            }
            return transactionStatus;
          } else {
            throw new Error("Payment Data is invalid");
          }
        case PaymentMethod.NET_BANKING:
          this.transactionRepository.startTransaction(
            transactionId,
            PaymentMethod.NET_BANKING,
            client,
            amount,
            bank
          );
          if (paymentData.type === PaymentMethod.NET_BANKING) {
            const transactionStatus: boolean =
              this.netBankingService.carryTransaction(
                bank,
                amount,
                paymentData
              );
            if (transactionStatus) {
              this.transactionRepository.completeTransaction(transactionId);
            }
            return transactionStatus;
          } else {
            throw new Error("Payment Data is invalid");
          }
        default:
          const paymentMethodFailSafe: never = paymentMethod;
          console.log(paymentMethodFailSafe);
          return false;
      }
    } catch (err) {
      this.transactionRepository.failTransaction(transactionId);
      throw err;
    }
  }
}

class PaymentGatewayClass {
  private PaymentGatewayData: PaymentGateway = {
    clients: [],
    banks: [],
    routerConfig: new Map<PaymentMethod, PGConfig[]>(),
  };
  constructor(private transactionService: TransactionService) {}

  private getClientIdx(clientName: string): number {
    try {
      const clientIdx: number = this.PaymentGatewayData.clients.findIndex(
        (client: Client) => client.name === clientName
      );
      if (clientIdx >= 0) {
        return clientIdx;
      }
      return -1;
    } catch (err) {
      throw err;
    }
  }

  checkClient(clientName: string): boolean {
    try {
      return this.getClientIdx(clientName) >= 0;
    } catch (err) {
      throw err;
    }
  }

  addClient(newClient: Client): Client {
    try {
      if (this.getClientIdx(newClient.name) >= 0) {
        this.PaymentGatewayData.clients.push(newClient);
        return newClient;
      }
      throw new Error("Client already exists");
    } catch (err) {
      throw err;
    }
  }

  removeClient(clientName: string) {
    try {
      this.PaymentGatewayData.clients = this.PaymentGatewayData.clients.filter(
        (client: Client) => client.name !== clientName
      );
    } catch (err) {
      throw err;
    }
  }

  listSupportedPaymodes(clientName?: string): PaymentMethod[] {
    try {
      if (clientName) {
        const clientIdx: number = this.checkClient(clientName);
        if (clientIdx >= 0) {
          return this.PaymentGatewayData.clients[clientIdx].optedPaymentMethods;
        }
        throw new Error("client does not exist in system");
      } else {
        return [...this.PaymentGatewayData.routerConfig.keys()];
      }
    } catch (err) {
      throw err;
    }
  }

  addSupportForPaymode(
    paymentMode: PaymentMethod,
    pgConfig: PGConfig[],
    clientName?: string
  ) {
    try {
      if (clientName) {
        const clientIdx: number = this.getClientIdx(clientName);
        if (clientIdx >= 0) {
          let clientPaymentMethods: PaymentMethod[] =
            this.PaymentGatewayData.clients[clientIdx].optedPaymentMethods;
          clientPaymentMethods = clientPaymentMethods.filter(
            (method: PaymentMethod) => method !== paymentMode
          );
          this.PaymentGatewayData.clients[clientIdx].optedPaymentMethods =
            clientPaymentMethods;
        }
        throw new Error("client does not exist in system");
      } else {
        if (!(paymentMode in this.PaymentGatewayData.routerConfig)) {
          this.PaymentGatewayData.routerConfig.set(paymentMode, pgConfig);
        }
        throw new Error("Payment mode already exists in Gateway");
      }
    } catch (err) {
      throw err;
    }
  }

  removePaymode(payMode: PaymentMethod, clientName?: string) {
    try {
      if (clientName) {
        const clientIdx: number = this.checkClient(clientName);
        if (clientIdx >= 0) {
          const clientPaymentMethods: PaymentMethod[] =
            this.PaymentGatewayData.clients[clientIdx].optedPaymentMethods;
          this.PaymentGatewayData.clients[clientIdx].optedPaymentMethods =
            clientPaymentMethods.filter(
              (method: PaymentMethod) => method !== payMode
            );
        }
        throw new Error("client does not exist in system");
      } else {
        // remove from each registered client
        this.PaymentGatewayData.clients.forEach((client) =>
          this.removePaymode(payMode, client.name)
        );
        this.PaymentGatewayData.routerConfig.delete(payMode);
      }
    } catch (err) {
      throw err;
    }
  }

  showDistribution() {
    try {
      this.PaymentGatewayData.routerConfig.forEach(
        (value: PGConfig[], key: PaymentMethod) => {
          console.log(`For payment method of ${key}`);
          value.forEach((pgConfig: PGConfig) => {
            console.log(`${pgConfig.bank} has ${pgConfig.percentage}`);
          });
        }
      );
    } catch (err) {
      throw err;
    }
  }

  private getBank(payMode: PaymentMethod): Bank {
    try {
      const pgConfigsForPayMode: PGConfig[] | undefined =
        this.PaymentGatewayData.routerConfig.get(payMode);

      if (pgConfigsForPayMode) {
        let totalUsage = 0;
        for (let i = 0; i < pgConfigsForPayMode.length; i++) {
          totalUsage += pgConfigsForPayMode[i].usage;
        }
        for (let i = 0; i < pgConfigsForPayMode.length; i++) {
          let bankUsagePercent =
            ((pgConfigsForPayMode[i].usage + 1) / (totalUsage + 1)) * 100;
          if (bankUsagePercent <= pgConfigsForPayMode[i].percentage) {
            return pgConfigsForPayMode[i].bank;
          }
        }
        throw new Error(
          "Something went wrong! No bank supports the usage support limit"
        );
      } else {
        throw new Error(
          `${payMode} payment method not supported by our system`
        );
      }
    } catch (err) {
      throw err;
    }
  }

  makePayment(
    paymentData: Card | UPI | NetBanking,
    payMode: PaymentMethod,
    client: string,
    amount: number
  ) {
    try {
      // get bank from router config
      const clientIdx: number = this.getClientIdx(client);
      if (
        payMode in
        this.PaymentGatewayData.clients[clientIdx].optedPaymentMethods
      ) {
        const bank: Bank = this.getBank(payMode);
        this.transactionService.makeTransaction(
          paymentData,
          payMode,
          client,
          amount,
          bank
        );
      }
      throw new Error(
        `${payMode} payment method not supported for client ${client}`
      );
    } catch (err) {
      throw err;
    }
  }
}